"""
author: fgasa
date: 2021-01-21
update: 2024-07-02
"""

import os
import pandas as pd

H2_LHV = 0.00295
CH4_LHV = 0.00983
report_key = 'DE-hydrogen-storage'  # 'DE-cavern-acaes'
load_path = r'\inputs\2030NEPC_DE-electricity.csv'
filling_level_path = r'\inputs\2030NEPC_filling_levels.csv'

def read_scenario(load_path, filling_level_path, target_key):
    """
    Returns:
    - df_load (pd.DataFrame): DataFrame containing the initial load profile from energy system model
    - df_storage (pd.DataFrame): DataFrame containing the storage filling level with power to gas conversion data
    - df (pd.DataFrame): clean DataFrame containing the processed power and flow rate metrics
    """
    try:
        df_load = pd.read_csv(load_path, sep=',', parse_dates=[0], index_col=0)
        # power rate from filling level consideres storage time dependet rate loss-> P2G 62.35
        df_storage = pd.read_csv(filling_level_path, sep=',', parse_dates=[0], index_col=0)
    except FileNotFoundError as e:
        print(f"Error: {e}")
        return None, None, None

    df = pd.DataFrame()
    df['DE-power energy system [MW]'] = df_load[target_key]
    df['DE-power storage [MW]'] = df_storage[target_key]

    # The energy system uses a negative sign to indicate the power of injected gas into the reservoir. 
    # The storage load profile assumes a minus sign to represent discharge from the reservoir to the energy grid.
    charge = df_load[target_key] < 0
    discharge = df_load[target_key] > 0

    df['power output energy system [MW]'] = df_load[discharge][target_key]
    df.fillna({'power output energy system [MW]': 0}, inplace=True)

    df['power input energy system [MW]'] = df_load[charge][target_key]
    df.fillna({'power input energy system [MW]': 0}, inplace=True)

    df['power diff storage [MW]'] = df_storage[target_key].diff()
    df.fillna({'power diff storage [MW': 0}, inplace=True)

    df['power input storage [MW]'] = df[charge]["power diff storage [MW]"]
    df.fillna({'power input storage [MW]': 0}, inplace=True)

    df['power output storage [MW]'] = df[discharge]["power diff storage [MW]"]
    df.fillna({'power output storage [MW]': 0}, inplace=True)

    df['injection flow rate [sm3/d]'] = df['power input storage [MW]'] * 24 / H2_LHV
    df['withdrawal flow rate [sm3/d]'] = df['power output storage [MW]'] * 24 / H2_LHV

    return df_load, df_storage, df
df_load, df_storage, df = read_scenario(load_path, filling_level_path, report_key)

def get_scenario_info(load_path, filling_level_path, target_key):
    print(f'Msg: Scenario name {os.path.basename(load_path)}')
    print(f'Msg: Storage type {target_key}')

    # Read scenario data
    df_load, df_storage, df = read_scenario(load_path, filling_level_path, target_key)

    charge = df_load[target_key] < 0
    discharge = df_load[target_key] > 0

    print(' Energy output [TWh]: ', df_load[discharge][target_key].sum() / 1e6)
    print(' Energy input [TWh]: ', -df_load[charge][target_key].sum() / 1e6)
    print(' Number discharge [-]: ', (df_load[discharge][target_key] == True).size)
    print(' Number charge [-]: ', (df_load[charge][target_key] == True).size)
    print(' Round trip efficiency [-]: ', -df_load[discharge][target_key].sum() /
          df_load[charge][target_key].sum())
    print(' Energy input(storage) [TWh]: ', -df[charge]['power input storage [MW]'].sum() / 1e6)
    print(' Energy output(storage) [TWh]: ', df[discharge]['power output storage [MW]'].sum() / 1e6)

    # return df
get_scenario_info(load_path, filling_level_path, report_key)

def generate_storage_schedule(df, well_no, min_WBHP, max_WBHP, output_filename):
    """
    Generates a storage schedule for the ECLIPSE simulator based on the given data. Another approach is group control.

    Parameters:
    - df (pd.DataFrame): clean DataFrame containing power and flow rate metrics
    - well_no (int): Number of wells in the storage facility
    - min_WBHP (float): Minimum well bottom hole pressure in bar
    - max_WBHP (float): Maximum well bottom hole pressure
    - output_filename (str): Output file name for the ECLIPSE schedule section
    """

    # df['injection flow rate [sm3/d]'] = df['power input storage [MW]'] * 86400 / H2_DENSITY
    # df['withdrawal flow rate [sm3/d]'] = df['power output storage [MW]'] * 86400 / H2_DENSITY
    power_target = df['DE-power energy system [MW]']

    # Section for ECLIPSE SCHEDULE

    well_names = ['WELL_C'] + [f'WELL_{i}' for i in range(1, well_no)]

    timestep = "/\nTSTEP \n 1*0.041666666666666664 /\n\n"
    inj_mode = "WCONINJE\n"
    with_mode = "WCONPROD\n"

    # Injection and withdrawal rate per well  ECLIPSE (20char limit)
    inje_VFR = (df['injection flow rate [sm3/d]'] / well_no).round(5)
    with_VFR = (df['withdrawal flow rate [sm3/d]'] / well_no).round(5)

    # write storage schedule file
    write_file = open(output_filename, "w")
    for i in range(len(power_target)):
        power_value = power_target.iloc[i]
        if power_value < 0:  # keep in minde, system opearates according energy system signs
            write_file.write(inj_mode)
            for j in range(well_no):
                # textline = str("    " + well_names[j] + " 'GAS'	'OPEN'	'RATE'   " + str(inje_VFR[i]) + "   1* " + str(max_WBHP) + " /\n")
                textline = f"    {well_names[j]} 'GAS' 'OPEN' 'RATE' {inje_VFR.iloc[i]} 1* {max_WBHP} /\n"
                write_file.write(textline)
            write_file.write(timestep)
        elif power_value > 0:  # Withdrawal mode
            write_file.write(with_mode)
            for j in range(well_no):
                textline = f"    {well_names[j]} 'OPEN' 'GRAT' 2* {with_VFR.iloc[i]} 2* {min_WBHP} /\n"
                write_file.write(textline)
            write_file.write(timestep)
        else:
            write_file.write(inj_mode)
            for j in range(well_no):
                textline = f"    {well_names[j]} 'GAS' 'OPEN' 'RATE' 0.0 1* {max_WBHP} /\n"
                write_file.write(textline)
            write_file.write(timestep)
generate_storage_schedule(df, well_no=21, min_WBHP=80, max_WBHP=130, output_filename='STORAGE_LOAD_PROFILE.INC')
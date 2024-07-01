RPTRST                                 
  BASIC=5 /
WCONPROD
    WELL_C 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_1 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_2 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_3 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_4 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_5 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_6 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_7 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_8 'OPEN' 'GRAT'  2*  2e5  2* 1* /
	WELL_9 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_10 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_11 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_12 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_13 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_14 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_15 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_16 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_17 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_18 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_19 'OPEN' 'GRAT'  2*  2e5  2* 1* /
    WELL_20 'OPEN' 'GRAT'  2*  2e5  2* 1* /
/
TSTEP 
 20*6 /
--												shut-in
WCONPROD
    WELL_C 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_1 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_2 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_3 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_4 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_5 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_6 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_7 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_8 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_9 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_10 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_11 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_12 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_13 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_14 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_15 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_16 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_17 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_18 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_19 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_20 'OPEN' 'GRAT'  2*  0  2* 1* /	
/
TSTEP 
 10*6 /
TSTEP 
 2*1 /
--												injection
WCONINJE
    WELL_C 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_1 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_2 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_3 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_4 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_5 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_6 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_7 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_8 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_9 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_10 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_11 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_12 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_13 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_14 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_15 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_16 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_17 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_18 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_19 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
    WELL_20 'GAS'	'OPEN'	'RATE'   2e5  1* 1* /
/
TSTEP 
 20*6 /

--												shut-in 
WCONPROD
	WELL_C 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_1 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_2 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_3 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_4 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_5 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_6 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_7 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_8 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_9 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_10 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_11 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_12 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_13 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_14 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_15 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_16 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_17 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_18 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_19 'OPEN' 'GRAT'  2*  0  2* 1* /
    WELL_20 'OPEN' 'GRAT'  2*  0  2* 1* /	
/
TSTEP 
 10*6 /

RPTRST                                 
  BASIC=2 /
  
TSTEP 
 2*1 /
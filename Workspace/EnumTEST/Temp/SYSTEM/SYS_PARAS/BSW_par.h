#include "DRV_par.h"

#if OEM_CAR == HKMC_RS4
const char ECU_ID[25] = "RS4 ADRV A.01 A.05 210609";
const char PART_NUMBER_LHD[15] = "99810T4000     ";
const char PART_NUMBER_RHD[15] = "99810T4000     ";
#elif OEM_CAR == HKMC_SG2
const char ECU_ID[25] = "SG2 ADRV A.00 A.00 201202";
const char PART_NUMBER_LHD[15] = "99810AO000     ";
const char PART_NUMBER_RHD[15] = "99810AO000     ";
#elif OEM_CAR == HKMC_CE
const char ECU_ID[25] = "CE  ADRV A.00 A.00 210416";
const char PART_NUMBER_LHD[15] = "99810KL000     ";
const char PART_NUMBER_RHD[15] = "99810KL000     ";
#else
#error Undefined OEM Car
#endif

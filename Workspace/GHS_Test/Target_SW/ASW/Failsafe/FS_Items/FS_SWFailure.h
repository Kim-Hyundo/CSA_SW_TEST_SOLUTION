/*
 * Author: Insub Song (insub.song@halla.com)
 * Date  : 2019.02.01
 */

#ifndef FS_SWFAILURE_H
#define FS_SWFAILURE_H

extern boolean variant_coding_fault;

void FS_SWFailureTest(void);

void FS_UpdateInfo_SWFailure(void);
void FS_SetDiagsta_SWFailure(void);
void FS_SetInhibit_SWFailure(void);

void FS_UpdateInfo_VariantCoding(void);
void FS_SetDiagsta_VariantCoding(void);
void FS_SetInhibit_VariantCoding(void);

#endif  /* FS_SWFAILURE_H */

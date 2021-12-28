#ifndef MCDC_FUNCTION_H
#define MCDC_FUNCTION_H

// struct list_data {
//   int count;
//   struct list_entry* data;
// };

#pragma pack 2
typedef struct {
     unsigned char  uc1;
     unsigned char  uc2;
     unsigned short us1;
     unsigned short us2;
     unsigned short us3;
} packed_struct;
#pragma pack 0


void mcdctest_function0(void);
int mcdctest_function1(int i);
int mcdctest_function2(int cnt);
void mcdctest_function3(unsigned char *CMD);
void mcdctest_function4(int num1, int num2, int num3, int num4);
void mcdctest_function5(int shift);
void mcdctest_function6(char* s1, char* s2, char* s3);
void mcdctest_function7(void);
int mcdctest_function8(void);
void mcdctest_function9(int cnt);

#endif 

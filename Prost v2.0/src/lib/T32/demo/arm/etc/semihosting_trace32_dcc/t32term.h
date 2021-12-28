
#ifdef	__cplusplus
extern "C" {
#endif

extern void T32_Term_PutBlock(const unsigned char * data, int size);
extern void T32_Term_GetBlock(unsigned char * data, int size);

extern int T32_Term_Getchar(void);
extern void T32_Term_Puts(const char * buffer);

extern int T32_Term_OpenFile(const char * fname, int mode);

#define T32_TERM_O_OPEN_EXISTING	0x00
#define T32_TERM_O_CREATE_TRUNC		0x04
#define T32_TERM_O_CREATE_APPEND	0x08

#define T32_TERM_O_RDONLY		0x00
#define T32_TERM_O_WRONLY		0x02
#define T32_TERM_O_RDWR			0x02

#define T32_TERM_O_ASCII		0x00
#define T32_TERM_O_BINARY		0x01


extern int T32_Term_CloseFile(int handle);
extern int T32_Term_ReadFile(int handle, char * buffer, int len);
extern int T32_Term_WriteFile(int handle, char * buffer, int len);
extern int T32_Term_SeekFile(int handle, long pos);
extern long T32_Term_TellFile(int handle);
extern long T32_Term_TellSizeFile(int handle);
extern int T32_Term_GetTempName(char * name);
extern int T32_Term_Remove(char * fname);
extern int T32_Term_Rename(char * fname, char * fnamenew);

#ifdef	__cplusplus
}
#endif

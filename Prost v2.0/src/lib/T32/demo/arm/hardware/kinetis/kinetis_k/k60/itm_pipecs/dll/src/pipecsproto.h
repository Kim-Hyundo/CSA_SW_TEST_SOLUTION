#ifndef PIPECSPROTO_H_INCLUDED_
#define PIPECSPROTO_H_INCLUDED_

#if !defined(T32_STDINT_H)
// If T32_STDINT_H is NOT defined, then
// this file is included from code OUTSIDE of TRACE32.
// So this file is included to build a DLL (shared object).
#if defined(_MSC_VER)
	typedef          __int8  int8_t;
	typedef unsigned __int8  uint8_t;
	typedef          __int32 int32_t;
	typedef unsigned __int32 uint32_t;
	typedef          __int64 int64_t;
	typedef unsigned __int64 uint64_t;
#else /* #if defined(_MSC_VER) */
#       include <stdint.h>
#endif /* #if defined(_MSC_VER) else */

typedef void SPipeProtoInfoArray;
typedef void SPipeProtoInfoInternal;
typedef void SCustomTraceFile;

#endif /* #if !defined(T32_STDINT_H) */

#ifdef  __cplusplus
extern "C" {
#endif

#if !defined(T32_STDINT_H)
/* note: this is only used to switch to CoreSight mode */
#define PIPE_VERSION     11
#define PIPE_DLLMODE_CS   1

typedef struct SPipeProtoInfo SPipeProtoInfo;
struct SPipeProtoInfo {
	int version;
	int number;

	/* The following TRACE32 GUI functions can be called by the DLL. */
	int (*registerCallback)(SPipeProtoInfo *info, int type, void *callback, void *localdata, unsigned int flags);
	void (*puts)(SPipeProtoInfo *info, const char *str);
	int (*command)(SPipeProtoInfo *info, const char *str);
	int (*uartWrite)(SPipeProtoInfo *info, const unsigned char * buf, int len);
	void (*log)(SPipeProtoInfo *info, const unsigned char * ts, int type, const unsigned char *buf, int len);

	void *array; /* internal parameters */
	void *file;

	void (*putsArea)(SPipeProtoInfo *info, const char *name, const char *str);
	void *(*switchMode)(SPipeProtoInfo *info, int mode);
};
#endif /* #if !defined(T32_STDINT_H) */

typedef struct SPipeCSProtoInfo SPipeCSProtoInfo;
struct SPipeCSProtoInfo {
	int version;
	int number;

	SPipeProtoInfoArray *array; /* internal parameters */
	SPipeProtoInfoInternal *info;
	SCustomTraceFile *file;

	void (*putsArea)(SPipeCSProtoInfo *info, const char *area, const char *str);
	int (*registerCallback)(SPipeCSProtoInfo *info, int type, void *callback, void *localdata);
};

#define PIPECS_VERSION           2

#define PIPECS_CALLBACK_PROCESS_ATB(atbid)   (1|(((atbid)&0x7F)<<16))
#define PIPECS_CALLBACK_EXIT                  2
#define PIPECS_CALLBACK_PROCESS_ITM(atbid)   (3|(((atbid)&0x7F)<<16))
#define PIPECS_CALLBACK_PROCESS_STM(atbid)   (4|(((atbid)&0x7F)<<16))
#define PIPECS_CALLBACK_PROCESS_WRAPPED_TPIU  5
#define PIPECS_CALLBACK_PROCESS_RAW_TPIU      6
#define PIPECS_CALLBACK_FLUSHINIT             10
#define PIPECS_CALLBACK_GETBUFFER             11
#define PIPECS_CALLBACK_CMD                   12

#define PIPECS_GETBUFFER_SIZE                (260*1024)

#if !defined(T32_STDINT_H)

/*
	PIPECS_Init is called from TRACE32 when DLL is loaded
	PIPECS_Init needs to be implemented in the user code of the DLL
*/
extern int PIPECS_Init(SPipeCSProtoInfo *info, int argc, char **argv);

/* to be called by DLL user code */
extern void PIPECS_PutsArea(SPipeCSProtoInfo *info, const char *area, const char *str);
extern void PIPECS_PrintfArea(SPipeCSProtoInfo *info, const char *area, const char *format, ...);
extern int  PIPECS_RegisterCallback(SPipeCSProtoInfo *info, int type, void *callback, void *localdata);

#endif /* #if !defined(T32_STDINT_H) */

#ifdef  __cplusplus
}
#endif

#endif /* #ifndef PIPECSPROTO_H_INCLUDED_ */


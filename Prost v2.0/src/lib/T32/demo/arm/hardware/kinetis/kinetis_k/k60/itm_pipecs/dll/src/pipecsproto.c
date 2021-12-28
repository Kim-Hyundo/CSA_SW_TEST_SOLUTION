
// NOTE: This file is NOT compiled for TRACE32.
// It is compiled for a DLL (shared object) to interface with TRACE32

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#if defined(_MSC_VER)
#       define PIPEPROTO_DLLEXPORT __declspec(dllexport)
#else
#       define PIPEPROTO_DLLEXPORT
#endif
#include "pipecsproto.h"

PIPEPROTO_DLLEXPORT int PIPE_Interface(SPipeProtoInfo *info, int argc, char **argv)
{
	SPipeCSProtoInfo *infocs;
	infocs = NULL;
	if (info->version < PIPE_VERSION) {
		info->puts(info, "Library is too new to be used with this TRACE32 software. Aborting load!");
		return 128;
	}
	info->version = PIPE_VERSION;
	infocs = info->switchMode(info, PIPE_DLLMODE_CS);
	if (infocs == NULL) {
		info->puts(info, "Cannot switch to CoreSight mode!");
		return 129;
	}
	if (infocs->version < PIPECS_VERSION) {
		info->puts(info, "Library is too new to be used with this TRACE32 software. Aborting load!");
		return 128;
	}
	infocs->version = PIPECS_VERSION;
	return PIPECS_Init(infocs, argc, argv);
}

void PIPECS_PutsArea(SPipeCSProtoInfo *info, const char *area, const char *str)
{
	info->putsArea(info, area, str);
}

void PIPECS_PrintfArea(SPipeCSProtoInfo *info, const char *area, const char *format, ...)
{
	char line[4096];
	va_list ap;

	va_start(ap, format);
	vsnprintf(line, 4000, format, ap);
	va_end(ap);
	info->putsArea(info, area, line);
}

int PIPECS_RegisterCallback(SPipeCSProtoInfo *info, int type, void *callback, void *localdata)
{
	return info->registerCallback(info, type, callback, localdata);
}


#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <stdio.h>

typedef struct ProcessData
{
	pid_t pid;
	uint64_t mapsStart;
	uint64_t mapsSize;
} ProcessData;

extern FILE* dfile;

#define MODE_EXTERNAL() 1
#define MODE_QEMU_INJECT() 2
#define MODE_DMA() 3

#define DMSG(...) fprintf(dfile, __VA_ARGS__)
#define NMSG(...)
#define PASTE(A, B) A##B

#if (MVERBOSE >= 1)
#define MSG1 DMSG
#else
#define MSG1 NMSG
#endif

#if (MVERBOSE >= 2)
#define MSG2 DMSG
#else
#define MSG2 NMSG
#endif

#if (MVERBOSE >= 3)
#define MSG3 DMSG
#else
#define MSG3 NMSG
#endif

#if (MVERBOSE >= 4)
#define MSG4 DMSG
#else
#define MSG4 NMSG
#endif

#define MSG(LEVEL, ...) PASTE(MSG, LEVEL) (__VA_ARGS__)

#endif

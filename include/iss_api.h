#ifndef __ISS_API__
#define __ISS_API__
#endif

#include<stdio.h>
#include<inttypes.h>

unsigned char code_mem[1024];
unsigned char data_mem[256];

typedef struct bytestruct {
	unsigned char byte1;
	unsigned char byte2;
} bytestruct_t;

typedef struct cpu_contexts {
	unsigned char R[16];
	uint16_t *PC;
} cpu_contexts_t;

enum {
        MOV_Rn_DIR = 0x00,
        MOV_DIR_Rn = 0x01,
        MOV_MRn_Rm = 0x02,
        MOV_Rn_IMM = 0x03,
        ADD_Rn_Rm = 0x04,
        SUB_Rn_Rm = 0x05,
        JZ_Rn_REL = 0x08
};

int call_pipeline(const bytestruct_t bytecode, cpu_contexts_t* context);

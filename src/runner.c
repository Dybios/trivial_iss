#include<stdlib.h>
#include "iss_api.h"

unsigned char code_mem[1024] = {0xFF};
unsigned char data_mem[256] = {0xFF};

int main (void) {
	FILE* fileptr = NULL;
	long filelen;
	int ret = 0;

	bytestruct_t bytecode;
	cpu_contexts_t* context;

	context->PC = malloc(sizeof(unsigned char) * 2);

	fileptr = fopen("bin/code.bin", "rb");
	fseek(fileptr, 0, SEEK_END);
	filelen = ftell(fileptr);
	rewind(fileptr);
	fread(code_mem, filelen, 2, fileptr);

	fileptr = fopen("bin/data.bin", "rb");
	fseek(fileptr, 0, SEEK_END);
	filelen = ftell(fileptr);
	rewind(fileptr);
	fread(data_mem, filelen, 2, fileptr);

	context->PC = (uint16_t *) code_mem;

	while (1) {
		if (context->PC > (context->PC + 1024)) {
			printf("PC: Invalid Address.\n");
			return 0;
		}

		// Fetch
		bytecode.byte1 = context->PC[0] & 0xFF;
		bytecode.byte2 = context->PC[0] >> 8;

		ret = call_pipeline(bytecode, context);
		if (ret == 1) {
			printf("End of execution\n");
			break;
		}
	}

	fileptr = fopen("bin/ramdump", "wb+");
	fwrite(data_mem, sizeof(data_mem), 1, fileptr);

	fileptr = fopen("bin/regdump", "wb+");
	fwrite(context->R, sizeof(context->R), 1, fileptr);

	fclose(fileptr);

	return 0;
}

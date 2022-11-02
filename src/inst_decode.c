#include "iss_api.h"

int call_pipeline(const bytestruct_t bytecode, cpu_contexts_t* context)
{
        // Decode
        printf("PC: 0x%01lx, 0x%01x, 0x%01x\n", (uintptr_t) context->PC, bytecode.byte1, bytecode.byte2);
        switch ((bytecode.byte1 >> 4) & 0x0F) {
        case MOV_Rn_DIR:
                context->R[bytecode.byte1 & 0x0F] = data_mem[bytecode.byte2]; // Rn = M(Direct)
                break;
        case MOV_DIR_Rn:
                data_mem[bytecode.byte2] = context->R[bytecode.byte1 & 0x0F]; // M(Direct) = Rn
                break;
        case MOV_MRn_Rm:
                data_mem[ context->R[(bytecode.byte2 >> 4) & 0x0F]] = context->R[bytecode.byte2 & 0x0F]; // M(Rn) = Rm
                break;
        case MOV_Rn_IMM:
                context->R[bytecode.byte1 & 0x0F] = bytecode.byte2; // Rn = Immidiate
                break;
        case ADD_Rn_Rm:
                context->R[(bytecode.byte2 >> 4) & 0x0F] = context->R[(bytecode.byte2 >> 4) & 0x0F] + context->R[bytecode.byte2 & 0x0F]; // Rn = Rn + Rm
                break;
        case SUB_Rn_Rm:
                context->R[(bytecode.byte2 >> 4) & 0x0F] = context->R[(bytecode.byte2 >> 4) & 0x0F] - context->R[bytecode.byte2 & 0x0F]; // Rn = Rn - Rm
                break;
        case JZ_Rn_REL:
                context->PC += (context->R[bytecode.byte1 & 0x0F] == 0) ? (int8_t) bytecode.byte2 : 1; // Jump PC if Rn zero
                return 0;
        default:
                return 1;
        }
        context->PC++;
        return 0;
}

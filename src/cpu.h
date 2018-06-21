#ifndef CPU_H
#define CPU_H
/*
CPU  - total of 96 bits
  16bit Hi   Lo   Name/Function
  AF    A    -    Accumulator & Flags
  BC    B    C    BC
  DE    D    E    DE
  HL    H    L    HL
  SP    -    -    Stack Pointer
  PC    -    -    Program Counter/Pointer

The Flag Register F (lower 8bit of AF register)
  Bit  Name  Set Clr  Explanation
  7    Z    Z   NZ   Zero Flag
  6    NF     -   -    Add/Sub-Flag (set when add, or sub instr)
  5    HF     -   -    Half Carry Flag (set when carry of lower 4bits of the result)
  4    C    C   NC   Carry Flag
  3-0  -     -   -    Not used (always zero)
| 7 | 6 | 5 | 4 | 3  |2 | 1 | 0 | 
        8       |  0
*/
#include "defs.h"

typedef struct CPU_t {
	union {
		WORD AF;
		struct{	
			BYTE A;
			BYTE F; //lower 4 bits should always be zero!
		};
	};	
	union {
		WORD BC;
		struct{	
			BYTE B;
			BYTE C;
		};
	};
	union {
		WORD DE;
		struct{	
			BYTE D;
			BYTE E;
		};
	};
	union {
		WORD HL;
		struct{	
			BYTE H;
			BYTE L;
		};
	};
	WORD SP;
	WORD PC;
}CPU;

void cpu_init(CPU * cpu);
char * cpu_dump(const CPU * cpu);
void cpu_step(CPU * cpu);

//-------------------------HELPER MACROS -------------------------

//Register Accessors and modifiers
#define A cpu->A 
#define F cpu->F 
#define AF cpu->AF
#define B cpu->B 
#define C cpu->C
#define BC cpu->BC
#define D cpu->D 
#define E cpu->E
#define DE cpu->DE
#define H cpu->H 
#define L cpu->L
#define HL  cpu->HL

//Special registers
#define PC  cpu->PC 
#define SP 	cpu->SP


//Flag accessors and modfisers
//zero flag
#define FLAG_Z 		((F >> 7)  & 0x1)
#define FLAG_Z_SET (F = F & 0xF0 | 0x80) 		/* 1--- 0000 */ 
#define FLAG_Z_CLR (F &= 0x70) 					/* 0--- 0000 */

//add/sub flag
#define FLAG_N 		((F >> 6) & 0x1) 
#define FLAG_N_SET 	(F = F & 0xF0 | 0x40) 		/* -1-- 0000 */ 
#define FLAG_N_CLR 	(F &= 0xB0) 						/* -0-- 0000 */

//half carry 
#define FLAG_H 		((F >> 5) & 0x1)
#define FLAG_H_SET 	(F = F & 0xF0 | 0x20) 		/* --1- 0000 */ 
#define FLAG_H_CLR 	(F &= 0xD0) 						/* --0- 0000 */

//carry
#define FLAG_C 	   ((F >> 4) & 0x1)
#define FLAG_C_SET (F = F & 0xF0 | 0x10 ) 	/* ---1 0000 */ 
#define FLAG_C_CLR (F &= 0xE0) 					/* ---0 0000 */

#endif //CPU_H
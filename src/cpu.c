#include "cpu.h"
#include "op.h"

void cpu_init(CPU * cpu){
	SP = PC = 0;
	AF = BC = DE = HL = 0;
 }

char * cpu_dump(const CPU * cpu){
	char  * format = 
		"CPU STATE \n" 				
	  	"REGISTERS \n"
		"A  : 0x%02x \n"
		"BC : 0x%04x \n"
		"DE : 0x%04x\n"
		"HL : 0x%04x\n"
		"CONTROLS \n"
		"PC : 0x%04x \n"
		"SP : 0x%04x \n"
		"FLAGS \n"
		"Carry      : %u \n"
	  	"HalfCarry  : %u \n"
	  	"Add/Sub    : %u \n"
	  	"Zero       : %u \n";
	char * msg = malloc(sizeof(format));
	sprintf(msg, format,
		A,	BC,	DE,	HL,
		PC,	SP, 
		FLAG_C, FLAG_H,	FLAG_N,	FLAG_Z
	);  
	return msg;
}

void cpu_step(CPU * cpu)
{
		
}


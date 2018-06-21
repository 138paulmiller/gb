#ifndef INSTR_H
#define INSTR_H
/*
OPS 
	http://gameboy.mongenel.com/dmg/opcodes.html
	http://www.chrisantonellis.com/files/gameboy/gb-instructions.txt

	http://www.pastraiser.com/cpu/gameboy/gameboy_opcodes.html
	Contains all instructions in order of their OPCODES
	OPS[x] = OP, where x is opcode to OP 
*/
#include "defs.h"

//
typedef void (*OpFunc)(CPU*);

typedef struct OpCode_t {
	char *dis;			//disassembly mneumonic
	WORD len;				//operand length in bytes
	WORD cycles; 			//clock cycles per operation
//	OpFunc call; 		//function call
} OpCode;
/*
	OPS[0-255]		- Instructions
	OPS[256-511] 	- Extended instructions CB-prefixed 
*/

// const OpCode OPS[256];
// const OpCode OPS_ext[256];
extern const OpCode OPS[256];
extern const OpCode OPS_CB[256];

const OpCode OPS[256]	= 
{
	{"NOP", },
/*
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	//8
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	//16
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	//24
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	//32
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	//40
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	//48
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	//56
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	//64
*/
};

#endif //INSTR_H
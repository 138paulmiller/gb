/*
	GG EMu
*/

#include "cpu.h"

int main(){

	CPU * cpu = malloc(sizeof(CPU));


	cpu_init(cpu);
	FLAG_N_SET;
	FLAG_Z_SET;
	C = 0x00000001;
	printf("%s", cpu_dump(cpu));
	BC = 0x00000001 | (0x00000001 << 8);
	FLAG_Z_CLR;
	printf("%s", cpu_dump(cpu));

	free(cpu);
}
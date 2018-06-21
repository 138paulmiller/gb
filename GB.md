# GameBoy
Outline of (this)[http://marc.rawer.de/Gameboy/Docs/GBCPUman.pdf] online Gameboy reference.

(Opcodes)[http://www.devrs.com/gb/files/opcodes.html]

# Additional Resources
https://github.com/CTurt/Cinoop

## Specs

| Component  |   Detail    
------------ |	------------------------------------------------------
CPU          |	8-bit (Similar to the Z80 processor)
Clock Speed  |	4.194304MHz (4.295454MHz for SGB, max. 8.4MHz for CGB)
Work RAM     |	8K Byte (32K Byte for CGB)
Video RAM    |	8K Byte (16K Byte for CGB)
Screen Size  |	2.6"
Resolution   |	160x144 (20x18 tiles)
Max sprites  |	Max 40 per screen, 10 per line
Sprite sizes |	8x8 or 8x16
Palettes     |	1x4 BG, 2x3 OBJ (for CGB: 8x4 BG, 8x3 OBJ)
Colors       |	4 grayshades (32768 colors for CGB)
Horiz Sync   |	9198 KHz (9420 KHz for SGB)
Vert Sync    |	59.73 Hz (61.17 Hz for SGB)
Sound        |	4 channels with stereo sound
Power        |	DC6V 0.7W (DC3V 0.7W for GB Pocket, DC3V 0.6W for CGB)


|	Type		|	GB CPU Speed 	|	NOP Instruction
---------------	|	---------------	|	-----------------
Machine Cycles 	|	1.05MHz 		|	1 cycle
Clock Cycles   	|	4.19MHz 		|	4 cycles

Notice, 1 Machine Cycle = 4 clock cycles

## Memory Map

16bit addressing to ROM, RAM, and I/O registers.

| Address   |   Usage    
----------- |	------------------------------------------------------	
0000-3FFF	|	16KB ROM Bank 00     (in cartridge, fixed at bank 00)		One Cartridge Half 
4000-7FFF   |	16KB ROM Bank 01..NN (in cartridge, switchable bank number)	Other Cartridge Half
8000-9FFF   |	8KB Video RAM (VRAM) (switchable bank 0-1 in CGB Mode)
A000-BFFF   |	8KB External RAM     (in cartridge, switchable bank, if any)
C000-CFFF   |	4KB Work RAM Bank 0 (WRAM)
D000-DFFF   |	4KB Work RAM Bank 1 (WRAM)  (switchable bank 1-7 in CGB Mode)
E000-FDFF   |	Same as C000-DDFF (ECHO)    (typically not used)
FE00-FE9F   |	Sprite Attribute Table (OAM)
FEA0-FEFF   |	Not Usable
FF00-FF7F   |	I/O Ports
FF80-FFFE   |	High RAM (HRAM)
FFFF        |	Interrupt Enable Register

### Jump Vectors in First ROM Bank

The following addresses are supposed to be used as jump vectors:

  0000,0008,0010,0018,0020,0028,0030,0038   for RST commands
  0040,0048,0050,0058,0060                  for Interrupts

However, the memory may be used for any other purpose in case that your program doesn't use any (or only some) RST commands or Interrupts. 
RST commands are 1-byte opcodes that work similiar to CALL opcodes, except that the destination address is fixed.

### Internal RAM Echo
 The addresses E000-FE00 appear to access the internal
RAM the same as C000-DE00. (i.e. If you write a byte to
address E000 it will appear at C000 and E000.
Similarly, writing a byte to C000 will appear at C000
and E000.)

### Cartridge Header in First ROM Bank

The memory at 0100-014F contains the cartridge header. 
This area contains information about the program, its entry point, checksums, information about the used MBC chip, the ROM and RAM sizes, etc. 
Most of the bytes in this area are required to be specified correctly. 
For more information read the chapter about The Cartridge Header.

### External Memory and Hardware

The areas from 0000-7FFF and A000-BFFF may be used to connect external hardware. 
The first area is typically used to address ROM (read only, of course), cartridges with Memory Bank Controllers (MBCs)
are additionally using this area to output data (write only) to the MBC chip. 

The second area is often used to address external RAM, or to address other external hardware (Real Time Clock, etc). 
External memory is often battery buffered, and may hold saved game positions and high scrore tables (etc.) even when the gameboy is turned of, or when the cartridge is removed. 
For specific information read the chapter about Memory Bank Controllers.

Reserved Memory Locations
| 		| 	
-----	|---------------------------------------------------
0000	|	Restart $00 Address (RST $00 calls this address.)
0008	|	Restart $08 Address (RST $08 calls this address.)
0010	|	Restart $10 Address (RST $10 calls this address.)
0018	|	Restart $18 Address (RST $18 calls this address.)
0020	|	Restart $20 Address (RST $20 calls this address.)
0028	|	Restart $28 Address (RST $28 calls this address.)
0030	|	Restart $30 Address (RST $30 calls this address.)
0038	|	Restart $38 Address (RST $38 calls this address.)
0040	|	Vertical Blank Interrupt Start Address
0048	|	LCDC Status Interrupt Start Address
0050	|	Timer Overflow Interrupt Start Address
0058	|	Serial Transfer Completion Interrupt Start Address
0060	|	High-to-Low of P10-P13 Interrupt Start Address



















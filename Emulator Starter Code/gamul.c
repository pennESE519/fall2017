#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gamul.h"

// font set for rendering
const unsigned char fontset[FONTSET_SIZE] = {
	0xF0, 0x90, 0x90, 0x90, 0xF0,		// 0
	0x20, 0x60, 0x20, 0x20, 0x70,		// 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0,		// 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0,		// 3
	0x90, 0x90, 0xF0, 0x10, 0x10,		// 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0,		// 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0,		// 6
	0xF0, 0x10, 0x20, 0x40, 0x40,		// 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0,		// 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0,		// 9
	0xF0, 0x90, 0xF0, 0x90, 0x90,		// A
	0xE0, 0x90, 0xE0, 0x90, 0xE0,		// B
	0xF0, 0x80, 0x80, 0x80, 0xF0,		// C
	0xE0, 0x90, 0x90, 0x90, 0xE0,		// D
	0xF0, 0x80, 0xF0, 0x80, 0xF0,		// E
	0xF0, 0x80, 0xF0, 0x80, 0x80		// F
};


/*	FUNCTION: load_file
 *  -------------------
 *	Loads the given program/game
 *	PARAMETERS: 
 *  file_name: name of file to be loaded
 *  buffer: system memory which will hold program
 *	RETURNS: 0 if successful, -1 if file error
 */
int load_file(char *file_name, unsigned char *buffer)
{
	FILE *file;
	int file_size;

	// open file stream in binary read-only mode
	file = fopen(file_name, "rb");	//man 3 fopen
	
	fseek(file, 0, SEEK_END);	//man 3 fseek

	file_size = ftell(file);	//man 3 ftell

	rewind(file);				//man 3 rewind
	
	fread(buffer, 1, file_size, file);	//man 3 fread
	return 0;

}


/*	FUNCTION: display_func
 *  ----------------------
 *	Sample function that displays a pixel on the screen
 *	PARAMETERS: 
 *  gamer: architecture to be emulated, defined in gamul.h
 *	RETURNS: none
 */
void display_func(gamul8 *gamer)
{
	gamer->display[20][40] = 1;
	gamer->display[10][30] = 0;
}
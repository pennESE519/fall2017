#ifndef CHIP_H
#define CHIP_H

#define SCREEN_WIDTH	64
#define SCREEN_HEIGHT	32
#define FONTSET_SIZE	80

typedef struct chip8 {
	unsigned char display[SCREEN_WIDTH][SCREEN_HEIGHT];
} chip8;

extern void display_func(chip8 *chipper);

#endif
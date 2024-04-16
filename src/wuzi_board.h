#ifndef WUZI_BOARD_H
#define WUZI_BOARD_H

#include <stdio.h>
#include <string.h>

#define BOARD_MAX_WIDTH 30
#define BOARD_MAX_HEIGHT 30

#define BOARD_EMPTY_CHAR '*'

extern int board[BOARD_MAX_HEIGHT][BOARD_MAX_WIDTH];
extern int board_width;
extern int board_height;

int  set_board_sz(int w, int h);
void set_board_ele(int r,int c, int target_char);

void init_board( );
void show_board( );

#endif

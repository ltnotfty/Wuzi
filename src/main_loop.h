#ifndef MAIN_LOOP_H
#define MAIN_LOOP_H

#include<stdio.h>
#include "game_loop.h"

extern char * menu_content[];


void print_main_form();
void wuzi_main_loop();

int process_input(int ch);

void print_err_input(int ch);


#endif

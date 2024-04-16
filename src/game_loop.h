#ifndef GAME_P2P_H
#define GAME_P2P_H

#include <string.h>
#include <stdio.h>
#include "wuzi_board.h"
#include "wuzi_player.h"


enum _game_type {
   P2P,
   P2E,
} ;
typedef enum _game_type game_type;

enum  {
NPLAYER,
PLAYER1,
PLAYER2
};

static int dir[][2] = {
    {0,1},
    {1,0},
    {1,1},
    {1,-1}
};

enum {
  POS_TRUE,
  POS_OUT_OF_BOUND,
  POS_ALREADY_HAVE,
};


extern int chess_put[][BOARD_MAX_WIDTH];
extern const wuzi_player * player_slots[];
extern int turn;
extern game_type gm_tp;


inline int out_of_bound(int r,int c); 

void play_chess();
int check_winner();
int check_put_pos(int r, int c);
void game_loop();

void init_game();

void init_match();
void set_first_hand();


void game_frame();

void print_congraduation(int winner);


void set_put_chess(int who, int r, int c);
#endif

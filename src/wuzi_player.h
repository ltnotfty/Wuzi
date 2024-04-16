#ifndef WUZI_PLAYER_H
#define WUZI_PLAYER_H

#include <stdio.h>
#include <stddef.h>

enum _player_type {
     HUMAN,
     AI,
};
typedef enum _player_type player_type;

struct _wuzi_player {
    player_type p_type;
    char  board_char;
};





typedef struct _wuzi_player wuzi_player; 

extern wuzi_player player1;
extern wuzi_player player2;



void set_board_char( wuzi_player *player, char board_char);
void set_player_type( wuzi_player *player, player_type p_type);

void put_chess(const wuzi_player *p, int *r, int *c);




#endif

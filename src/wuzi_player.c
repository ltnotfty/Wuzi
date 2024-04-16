#include "wuzi_player.h"


wuzi_player player1;
wuzi_player player2;



void set_board_char( wuzi_player *player, char board_char)
{
   player->board_char = board_char;

}

void set_player_type( wuzi_player *player,player_type p_type)
{
    player->p_type = p_type;
}

void put_chess( const wuzi_player *p, int *r, int *c){
  
    if ( NULL == p)
	    return ;

    if ( p->p_type == HUMAN ) {
       scanf("%d%d", r, c);
    }
    else {
    
    }
}





#include "game_loop.h"






int chess_put[BOARD_MAX_HEIGHT][BOARD_MAX_WIDTH];

const wuzi_player *player_slots[2]; 
int turn;
game_type gm_tp;


void init_game()
{
    set_board_char(&player1, 'O');
    set_board_char(&player2, 'X');

    if (gm_tp == P2E )
	    set_player_type( &player2, AI );

    player_slots[0] = &player1;
    player_slots[1] = &player2;
}

void init_match()
{ 
    init_board();
    memset(chess_put, NPLAYER, sizeof (chess_put));
    turn=0;    
    

}

void game_loop()
{
    init_game(); 

     for ( ; ; ) {
         init_match(); 
         set_first_hand();
	 play_chess();

	 if ( !play_again( )) 
	     break;
     }	     

}


void play_chess() 
{
  
    for ( ; ; ) {
       
       int r,c;
       
       do{
	    // draw frame
            game_frame();
	    put_chess(player_slots[turn],&r, &c);
       }
       while (check_put_pos(r,c));
        
        set_put_chess( turn,r, c);

	int winner=check_winner();

	if ( winner ) {
            print_congraduation( winner );
	    break;
	}
        turn ^= 1;
    }


}


int play_again() 
{
 // clear screen
 // print info: r for a new game
 
 // if get r return 1
 // else return 0
    system("clear");

    printf("r for a new game, else return\n");
   
    int ch = getchar();

    if ( ch == 'r')
	    return 1;
    return 0;
}


void game_frame()
{
    system("clear");
    show_board();

    printf("it's %d's turn to put chess\n", turn);

    printf("put foramt: (r,c): ");
}


int check_winner()
{

    for (int i = 1;i <= board_height;i++ ) {

        for (int j = 1;j <= board_width;j++ ) {
            
	    int r = i;
	    int c = j;
	    if ( chess_put[r][c] == NPLAYER)
		    continue;
            for (int k = 0; k < 4;k++) {
               int lr = r + 4 * dir[k][0];
	       int lc = c + 4 * dir[k][1];

	       if ( out_of_bound(lr, lc) )
		       continue;
               int nr = r + dir[k][0];
	       int nc = c + dir[k][1];
	       while ( !(r  == lr && c == lc) && 
	          chess_put[nr][nc] == chess_put[r][c]){
                   r = nr, c = nc;
		   nr = nr + dir[k][0];
		   nc = nc + dir[k][1];
	       }
               if ( r == lr && c == lc ) {
                   return chess_put[r][c]; 
	       }
	    }

	}
    }
    
    return NPLAYER;
}


void print_congraduation(int winner)
{
    system("clear");
    
    printf("player %d win\n", winner);
    sleep(3);
}


void set_first_hand() {
system("clear");

printf("player2 first ? [y] for yes: ");

char c = 0;
scanf("\n%c", &c);


   sleep(3);
if ( c == 'y') {
       printf("\n player 2 first!\n");
	turn = 1;
}
system("clear");
}

void set_put_chess(int who, int r, int c)
{
   
    chess_put[r][c] = who + 1;
   
    set_board_ele(r, c, player_slots[turn]->board_char); 
}

int check_put_pos(int r, int c)
{
    if ( out_of_bound(r, c)) {
          printf("pos out of bound\n");
          sleep(3);
    	  return POS_OUT_OF_BOUND;	    
    }
    if ( chess_put[r][c] != NPLAYER ) {
          printf("pos already have chess!\n");
	  sleep(3);
	  return POS_ALREADY_HAVE;
    }

    return POS_TRUE;
}

int out_of_bound(int r, int c)
{
    if ( r < 1 || c < 1 || r > board_height || c > board_width )
	    return 1;
    return 0;
}

#include "wuzi_board.h"


int board[BOARD_MAX_HEIGHT][BOARD_MAX_WIDTH];
int board_width;
int board_height;


int set_board_sz(int w, int h)
{
    if ( w > BOARD_MAX_WIDTH )
	    return 0;
    if ( h > BOARD_MAX_HEIGHT )
	    return 0;

    board_width  = w;
    board_height = h;

    return 1;
}

void show_board( )
{
    
    for (int i = 0; i <= board_height; ++i) {
        for (int j = 0;j <= board_width; ++j) {
           
	    // print first line
	    if ( !i ) {
                printf("  %d", j);
	    }
	    else if ( !j ) {
                printf("  %d", i);
	    } 
	    else {
            
		printf("  %c", board[i-1][j-1]);
          
	    }
  
	}
        // print '\n' every line
	printf("\n");
    }

}

void init_board( )
{
   set_board_sz(15, 15);
   memset(board, BOARD_EMPTY_CHAR, sizeof(board) );
}


void set_board_ele(int r, int c, int tc)
{
    if ( r < 1 || r > board_height)
	    return;
    if ( c < 1 || c > board_width )
	    return;

    board[ r - 1 ][ c - 1 ] = tc;



}


#include "main_loop.h"

char *menu_content[] = {
   "press [1] for P2P",
   "press [2] for P2E",
   "press [q] to quit the game"
};

void print_main_form() 
{
    system("clear");
    int it_sz = sizeof(menu_content) / sizeof (menu_content[0]);
    for (int i = 0; i < it_sz; ++i) {
        printf("%s\n", menu_content[i]);
    }

    printf("please input the control char: \n");
}
void wuzi_main_loop() 
{

    for ( ; ; ) {
        
	print_main_form();
        int ch = getchar();
        if ( process_input(ch) ) 
		break;
    }
}
int process_input(int ch)
{
    switch(ch) {
       case '1':
	       gm_tp = P2P;
	       game_loop();
	       break;
       case '2':
	       gm_tp = P2E;
	       game_loop();
	       // set player type
	       break;
       case 'q':
	       return 1;
	       break;
       default:
	       
	       break;
    }

    return 0;
}
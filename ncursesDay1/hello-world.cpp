#include <curses.h>

int main() {
    // Call the initiate screen routing
    initscr();			/* Start curses mode 		  */
	printw("Hello World !!!");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	
    // lets us see the screen before it closes faster than lightning
    getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

    return 0;
}
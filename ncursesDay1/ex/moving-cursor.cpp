#include <ncurses.h>
#include <iostream>
#include <unistd.h>

using namespace std;


void printLorem() {
  printw("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");

}

void moveCursor() {
  int posX = 0, posY = 0;
  
  // Move cursor to the beggining of the text
  wmove(stdscr, posX, posY);


  // Increment posX by 7
  // Decrement posX by 3
  // Increment posX by 5
  
  // Get the dimension of the window
  int rows, cols;
  getmaxyx(stdscr, rows, cols);

  // Print the rows and cols of the stdscr
  printw("rows: %d, cols: %d", rows, cols);
  
  for (int posX = 0; posX <= cols; posX++) {
    move(posY, posX);
    refresh();
    usleep(100000);
  }


  cout << "rows: " << rows << endl;
  cout << "cols: " << cols << endl;
}


int main() {
  // A program that will display text and move the cursor over the text
  // The cursor will go around the stdscr in a square
  // The cursor will move 7 times forward, 3 backwards, and 5 forward
  // It should go down even lines each step and keep repating till end of line
  
  
  initscr();  /* Start curses mode  */
  raw();    /*  line buffering disabled*/
  noecho(); /*  Don't echo*/
  
  printw("Hey ncurses!");
  printw("\n");
  
  // Print ipsum dipsum
  printLorem();

  // Start of main movement
  

  moveCursor();

  refresh();
  getch();
  endwin();
}

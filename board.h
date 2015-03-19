#ifndef BOARD_H
#define BOARD_H
/* Place to put all of my definitions etc. */

typedef struct{
    int row;
    int col;
    int mine_num;
    char *values;
    char *status;
    char *visit;
}board_t;


char * init_board(int , int , char);
void place_mine(board_t *);
void increase_board_value(board_t , int , int );
void place_hint(board_t );
void print_board(board_t , int*);
#endif





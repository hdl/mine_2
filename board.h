#ifndef BOARD_H
#define BOARD_H
/* Place to put all of my definitions etc. */

typedef struct{
    int row;
    int col;
    int mine_num;
    char *values;
    char *user_view;
    char *dfs_flag;
}board_t;


void place_mine(board_t *);
void increase_board_value(board_t , int , int );
void place_hint(board_t );
void print_board(board_t , int*);
#endif





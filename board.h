#ifndef BOARD_H
#define BOARD_H
/* Place to put all of my definitions etc. */

typedef struct{
    int row;
    int col;
    int mine_num;
    int *mine_left;
    unsigned int seed;
    char *values;
    char *status;
    char *visit; // prepared for recsive reveal
}board_t;


char * init_board(int , int , char);
void place_mine(board_t *);
void set_hint(board_t , int , int );
void place_hint(board_t );
void print_value(char *, int , int );
void print_status(board_t );
#endif





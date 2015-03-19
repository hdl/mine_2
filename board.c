#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h"

/*
    all the function regarding board are declared here.
*/



/*
    Board initilization:
    @ rows: number of row
    @ cols: number of column
    @ value: what was put

*/
char * init_board(int rows, int cols, char v){
    char *board = (char *)malloc(sizeof(char) * cols * rows);
    memset(board, v, cols * rows);
    return board;
}


/*
    place_mine is used to place random mins with all the info in baord
*/
void place_mine(board_t *board){
    int random_row=0;
    int random_col=0;
    int counter=0;
    srand(board->seed);
    for(;;){
        random_row = rand() % board->row;
        random_col = rand() % board->col;

        if(board->values[random_row * board->col + random_col] != '*'){
            printf("Placing mine at %d, %d\n", random_row, random_col);
            board->values[random_row * board->col + random_col]='*';
            counter++;
        }else{
            continue;
        }
        if(counter == board->mine_num)
            return;

    }

}

/*
    set_hint is used to place hint number for board[i,j]
*/
void set_hint(board_t board, int i, int j)
{
    if( i<0 || i>=board.row || j<0 || j>=board.col)
        return;
    else{
        if(board.values[i*board.col + j]!='*')
            board.values[i*board.col + j]++;

    }
    return;

}

/*
    place_hint is called once for hint number init
*/
void place_hint(board_t board){
    int i, j;
    for(i=0; i<board.row; i++)
        for(j=0; j<board.col; j++){
            if(board.values[i*board.col + j] == '*'){
                set_hint(board, i-1, j-1);
                set_hint(board, i-1, j);
                set_hint(board, i-1, j+1);
                set_hint(board, i, j-1);
                set_hint(board, i, j+1);
                set_hint(board, i+1, j-1);
                set_hint(board, i+1, j);
                set_hint(board, i+1, j+1);
            }

        }
}












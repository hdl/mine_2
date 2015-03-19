#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h"

/*
    all the function regarding board are declared here.
*/




/*
    increase one on for hint value if neighbor is mine
*/
    void increase_board_value(board_t board, int i, int j)
    {
        if(i>=0 && i< board.row && j>=0 && j<board.col && board.hint_value[i*board.col + j]!='*')
            board.hint_value[i*board.col + j]++;
    }

/*
    place hint number
*/
    void place_hint(board_t board){
        int i, j;
        for(i=0; i<board.row; i++)
            for(j=0; j<board.col; j++){
                if(board.hint_value[i*board.col + j] == '*'){
                    increase_board_value(board, i-1, j-1);
                    increase_board_value(board, i-1, j);
                    increase_board_value(board, i-1, j+1);
                    increase_board_value(board, i, j-1);
                    increase_board_value(board, i, j+1);
                    increase_board_value(board, i+1, j-1);
                    increase_board_value(board, i+1, j);
                    increase_board_value(board, i+1, j+1);
                }

            }
        }


/*
    place random mines on board
*/
    void place_mine(board_t *board){
        int random_row=0;
        int random_col=0;
        int counter=0;
        for(;;){
            random_row = rand() % board->row;
            random_col = rand() % board->col;

            if(board->hint_value[random_row * board->col + random_col] != '*'){
                printf("Placing mine at %d, %d\n", random_row, random_col);
                board->hint_value[random_row * board->col + random_col]='*';
                counter++;
                if(counter == board->mine_num)
                    return;
            }

        }

    }













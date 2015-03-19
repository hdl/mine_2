#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h"


/*
    Print board status duing the game, which is shown to the player
*/
void print_board(board_t board){
    int i,j;
    int num_rows = board.row;
    int num_columns = board.col;
    printf("There are %d mines left\n", *board.mine_left);
    for(i=num_rows-1; i>=0; i--){
        printf("%d ", i);
        for(j=0; j<num_columns-1; j++){
            if(board.status[i * num_columns + j]=='r') //r means revealed
                printf("%c ", board.values[i * num_columns + j]);
            else
                printf("%c ", board.status[i * num_columns + j]);
        }
        if(board.status[i * num_columns + j]=='r')
            printf("%c\n", board.values[i * num_columns + j]);
        else
            printf("%c\n", board.status[i * num_columns + j]);

    }
    // last line
    printf("  ");
    for(i=0; i<num_columns-1; i++)
        printf("%d ",i);
    printf("%d\n",i);
}

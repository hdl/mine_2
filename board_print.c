#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h"


/*
    Print board status duing the game, which is shown to the player
*/
void print_board(board_t board, int *left){
    int i,j;
    printf("There are %d mines left\n", *left);
    for(i=board.row-1; i>=0; i--){
        printf("%d ", i);
        for(j=0; j<board.col-1; j++){
            if(board.status[i * board.col + j]=='r')
                printf("%c ", board.values[i * board.col + j]);
            else
                printf("%c ", board.status[i * board.col + j]);
        }
        if(board.status[i * board.col + j]=='r')
            printf("%c\n", board.values[i * board.col + j]);
        else
            printf("%c\n", board.status[i * board.col + j]);

    }
    printf("  ");
    for(i=0; i<board.col-1; i++)
        printf("%d ",i);
    printf("%d\n",i);
}

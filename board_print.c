#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h"


void print_board(board_t board, int *left){
    int i,j;
    printf("There are %d mines left\n", *left);
    for(i=board.row-1; i>=0; i--){
        printf("%d ", i);
        for(j=0; j<board.col-1; j++){
            if(board.user_view[i * board.col + j]=='r')
                printf("%c ", board.hint_value[i * board.col + j]);
            else
                printf("%c ", board.user_view[i * board.col + j]);
        }
        if(board.user_view[i * board.col + j]=='r')
            printf("%c\n", board.hint_value[i * board.col + j]);
        else
            printf("%c\n", board.user_view[i * board.col + j]);

    }
    printf("  ");
    for(i=0; i<board.col-1; i++)
        printf("%d ",i);
    printf("%d\n",i);
}

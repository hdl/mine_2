
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h"
#include "play.h"


/*
    Print board real vales, the final results
*/
void show_result(char *board, int num_rows, int num_columns, int result){
    int i,j;
    for(i=num_rows-1; i>=0; i--){
        printf("%d ", i);
        for(j=0; j<num_columns-1; j++)
            printf("%c ", board[i * num_columns + j]);
        printf("%c\n", board[i * num_columns + j]);
    }
    printf("  ");
    for(i=0; i<num_columns-1; i++)
        printf("%d ",i);
    printf("%d\n",i);

    if(result == 0)
        printf("You Lost :(\n");
    else
        printf("You Won!!\n");

    exit(0);


}


/*
    Make action on board[action_row, action_col] with a char which is action
*/
void make_action(board_t board, int action_row, int action_col, char action){
    int i,j;
    board.status[action_row * board.col + action_col] = action;

    if(action == '!'){
        (*board.mine_left)--;
    }
    if(action == 'r' && board.values[action_row * board.col + action_col]=='*'){
        show_result(board.values, board.row, board.col, 0);
    }

    if(action == 'r' && board.values[action_row * board.col + action_col]=='0'){
        //printf("here?\n");
        recsive_reveal(board, action_row, action_col);
    }

    // check
    for(i=0; i<board.row; i++)
        for(j=0; j<board.col; j++){
            if(board.values[i*board.col+j] != '*' && board.status[i*board.col+j]!='r'){
                return;
            }

            if(board.values[i*board.col+j] == '*' && board.status[i*board.col+j]!='!'){
                return;
            }

        }
    show_result(board.values, board.row, board.col, 1);

}



/*
    This is a recusive funtion, in case of a area of 0 is triggered
*/
void recsive_reveal(board_t board, int action_row, int action_col){


    //printf("current: %d, %d\n", action_row, action_col);
    if(action_col<0 || action_row<0 || action_row>=board.row || action_col >= board.col ){ //terminated
        //printf("return because terminated\n");
        return;
    }
    if( board.status[action_row*board.col +action_col]=='?' || board.status[action_row*board.col +action_col]=='!' ){

        board.visit[action_row * board.col + action_col]=1;
        return;
    }

    if(board.values[action_row * board.col + action_col]!='0'){  // base
        //printf("return because base");
        board.status[action_row * board.col + action_col]='r';
        return;
    }

    if(board.visit[action_row * board.col + action_col]==1){  // pruning
        //printf("return because visted\n");
        return;
    }
    if(board.values[action_row * board.col + action_col]=='0'){
        board.visit[action_row * board.col + action_col]=1;
        board.status[action_row * board.col + action_col]='r';
    }

    if(board.values[action_row*board.col + action_col] == '0'){
        recsive_reveal(board, action_row-1, action_col-1);
        recsive_reveal(board, action_row-1, action_col);
        recsive_reveal(board, action_row-1, action_col+1);
        recsive_reveal(board, action_row, action_col-1);
        recsive_reveal(board, action_row, action_col+1);
        recsive_reveal(board, action_row+1, action_col-1);
        recsive_reveal(board, action_row+1, action_col);
        recsive_reveal(board, action_row+1, action_col+1);
    }
    return ;
}

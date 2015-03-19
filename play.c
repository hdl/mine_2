
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h"
#include "play.h"


/*
    dfs to reveal board if 0
*/
void dfs(board_t board, int row, int col){

    if(board.dfs_flag[row * board.col + col]==1 || col<0 || row<0 || row>=board.row || col >= board.col ){ //terminated
        return;
    }
    if( board.user_view[row*board.col +col]=='?' || board.user_view[row*board.col +col]=='!' ){
        board.dfs_flag[row * board.col + col]=1;
        return;
    }

    if(board.values[row * board.col + col]!='0'){  // base
        board.user_view[row * board.col + col]='r';
        return;
    }

    if(board.values[row*board.col + col] == '0'){
        board.dfs_flag[row * board.col + col]=1;
        board.user_view[row * board.col + col]='r';
        dfs(board, row+1, col-1);
        dfs(board, row+1, col);
        dfs(board, row+1, col+1);
        dfs(board, row-1, col-1);
        dfs(board, row-1, col);
        dfs(board, row-1, col+1);
        dfs(board, row, col-1);
        dfs(board, row, col+1);
    }
    return ;
}


/*
    Make action on board[row, col] with a char which is action
*/
void play(board_t board, int row, int col, char action, int *left){
    int i,j;
    board.user_view[row * board.col + col] = action;

    if(action == '!'){
        (*left)--;
    }

    if(action == 'r' && board.values[row * board.col + col]=='0'){
        dfs(board, row, col);
    }

    if(action == 'r' && board.values[row * board.col + col]=='*'){
        show_result(board.values, board.row, board.col, 0);
    }



    // check win or not
    for(i=0; i<board.row; i++)
        for(j=0; j<board.col; j++){
            if(board.values[i*board.col+j] != '*' && board.user_view[i*board.col+j]!='r'){
                return;
            }

            if(board.values[i*board.col+j] == '*' && board.user_view[i*board.col+j]!='!'){
                return;
            }

        }
    // if runs here, win!
    show_result(board.values, board.row, board.col, 1);

}


/*
    show final result and board after reveal
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





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
    Make action on board[row, col] with a char which is action
*/
void make_action(board_t board, int row, int col, char action, int *left){
    int i,j;
    board.status[row * board.col + col] = action;

    if(action == '!'){
        (*left)--;
    }
    if(action == 'r' && board.values[row * board.col + col]=='*'){
        show_result(board.values, board.row, board.col, 0);
    }

    if(action == 'r' && board.values[row * board.col + col]=='0'){
        //printf("here?\n");
        dfs(board, row, col);
    }

    // check win or not
    for(i=0; i<board.row; i++)
        for(j=0; j<board.col; j++){
            if(board.values[i*board.col+j] != '*' && board.status[i*board.col+j]!='r'){
                return;
            }

            if(board.values[i*board.col+j] == '*' && board.status[i*board.col+j]!='!'){
                return;
            }

        }
    // if runs here, win!
    show_result(board.values, board.row, board.col, 1);

}



/*
    This is a recusive funtion, in case of a area of 0 is triggered
*/
void dfs(board_t board, int row, int col){

    if(board.visit[row * board.col + col]==1 || col<0 || row<0 || row>=board.row || col >= board.col ){ //terminated
        return;
    }
    if( board.status[row*board.col +col]=='?' || board.status[row*board.col +col]=='!' ){
        board.visit[row * board.col + col]=1;
        return;
    }

    if(board.values[row * board.col + col]!='0'){  // base
        board.status[row * board.col + col]='r';
        return;
    }

    if(board.values[row * board.col + col]=='0'){
        board.visit[row * board.col + col]=1;
        board.status[row * board.col + col]='r';
    }

    if(board.values[row*board.col + col] == '0'){
        dfs(board, row-1, col-1);
        dfs(board, row-1, col);
        dfs(board, row-1, col+1);
        dfs(board, row, col-1);
        dfs(board, row, col+1);
        dfs(board, row+1, col-1);
        dfs(board, row+1, col);
        dfs(board, row+1, col+1);
    }
    return ;
}

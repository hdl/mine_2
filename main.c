#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h"
#include "play.h"

int main(int argc, char *argv[])
{
    board_t board;
    int left;
    int play_row=0;
    int play_col=0;
    int action;

    if(argc >6){
        printf("Too many arguments. Usage:\n./mine_sweeper.out num_rows num_cols num_mines [seed])\n");
        exit(0);
    }
    if(argc <4){
        printf("Not enough arguments. Usage:\n./mine_sweeper.out num_rows num_cols num_mines [seed])\n");
        exit(0);
    }

    board.row = atoi(argv[1]);
    board.col = atoi(argv[2]);
    board.mine_num = atoi(argv[3]);
    left = atoi(argv[3]);
    if(argc == 5)
        srand(atoi(argv[4]));
    else
        srand(time(NULL));


    board.status = (char *)malloc(sizeof(char) * board.col * board.row);
    memset(board.status, '#', board.col * board.row);
    board.visit = (char *)malloc(sizeof(char) * board.col * board.row);
    memset(board.visit, 0, board.col * board.row);
    board.values = (char *)malloc(sizeof(char) * board.col * board.row);
    memset(board.values, '0', board.col * board.row);


    place_mine(&board);
    place_hint(board);

    print_board(board, &left);

    while(1){

        printf("Enter row a row between 0-%d and a column between 0-%d: ", board.row-1, board.col-1);
        scanf("%d %d", &play_row, &play_col);

        // invalid action
        if(play_row<0 || play_row>board.row-1 || play_col<0 || play_col> board.col-1)
            continue;


        if(board.status[play_row * board.col + play_col]=='r'){
            printf("This tile is already revealed.\n");
            continue;
        }else if(board.status[play_row * board.col + play_col]=='?'){
            printf("Enter Action\n0. UnQuestion\n1. Cancel\nAction: ");
            scanf("%d", &action);
            if(action == 0)
                board.status[play_row * board.col + play_col] = '#';
            else
                continue;
        }else if(board.status[play_row * board.col + play_col]=='!'){
            printf("Enter Action\n0. UnMark\n1. Cancel\nAction: ");
            scanf("%d", &action);
            if(action == 0){
                board.status[play_row * board.col + play_col] = '#';
                left++;
            }
            else
                continue;
        } else{
            printf("Enter Action\n0. Reveal\n1. Question\n2. Mark\n3. Cancel\nAction: ");
            scanf("%d", &action);

            if(action == 0){
                if(board.status[play_row * board.col + play_col] == 'r'){
                    printf("This tile is already revealed.\n");
                    continue;
                }else
                    play(board, play_row, play_col, 'r', &left);
            }
            else if(action == 1)
                play(board, play_row, play_col, '?', &left);
            else if(action == 2)
                play(board, play_row, play_col, '!', &left);
            else
                continue;

        }
        print_board(board, &left);

    }

}

#include <stdio.h>
#define SIZE 3

//function that prints out the ticktactoe board
void printBoard(char board[SIZE][SIZE]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            printf("%c ", board[i][j]);
            if (j < 2) {
                printf("| ");
            }
        }
        printf("\n");
    }
}

//function that test if someone has won
int checkWin(char board[SIZE][SIZE]) {
    int charVal;
    int crossOne = board[0][0]+board[1][1]+board[2][2];
    int crossTwo = board[0][2]+board[1][1]+board[2][0];
    int win = 0;
    for (int i = 0; i < 3; i++) {
        charVal = board[i][0]+board[i][1]+board[i][2];
        if (charVal == 264 || charVal == 237) {
            win = 1;
        }
    }
    for (int j = 0; j < 3; j++) {
        charVal = board[0][j]+board[1][j]+board[2][j];
        if (charVal == 264 || charVal == 237) {
            win = 1;
        }
    }
    if (crossOne == 264 || crossOne == 237) {
        win = 1;
    }
    if (crossTwo == 264 || crossTwo == 237) {
        win = 1;
    }
    return win;
    
}

int main() {
    //instance variables
    char board[SIZE][SIZE] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int win = 0;
    int turn = 1;
    char let = 'X';
    char row;
    char col;

    printf("x goes first\n");

    //game loop, resolves once there is a winner
    while (win != 1) {
        printBoard(board);
        printf("TURN\n %d", turn);
        printf("Enter row. T, M, B: \n");
        scanf(" %c", &row);
        printf("Enter col. L, M, R: \n");
        scanf(" %c", &col);

        //handles input and places X or O in spot
        switch (row) {
        case 't':
            switch (col) {
                case 'l':
                    board[0][0] = let;
                    break;
                case 'm':
                    board[0][1] = let;
                    break;
                case 'r':
                    board[0][2] = let;
                    break;
                default:
                    printf("error");
                    break;
            }
            break;
        case 'm':
            switch (col) {
                case 'l':
                    board[1][0] = let;
                    break;
                case 'm':
                    board[1][1] = let;
                    break;
                case 'r':
                    board[1][2] = let;
                    break;
                default:
                    printf("error");
                    break;
            }
            break;
        case 'b':
            switch (col) {
                case 'l':
                    board[2][0] = let;
                    break;
                case 'm':
                    board[2][1] = let;
                    break;
                case 'r':
                    board[2][2] = let;
                    break;
                default:
                    printf("error");
                    break;
            }
            break;
        
        default:
            printf("error");
            break;
        }

        if (let == 'X') {
            let = 'Y';
        } else {
            let = 'X';
        }
        turn++;
        win = checkWin(board);
        printf("win: %d\n", win);
    }
    return 0;
}
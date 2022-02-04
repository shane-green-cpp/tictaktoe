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

    //this loop determins if a row is a win
    for (int i = 0; i < 3; i++) {
        charVal = board[i][0]+board[i][1]+board[i][2];
        if (charVal == 264 || charVal == 237) {
            win = 1;
        }
    }
    //this loop determins if a col is a win
    for (int j = 0; j < 3; j++) {
        charVal = board[0][j]+board[1][j]+board[2][j];
        if (charVal == 264 || charVal == 237) {
            win = 1;
        }
    }
    //checks cross
    printf("crossOne : %d\n", crossOne);
    if (crossOne == 264 || crossOne == 237) {
        win = 1;
    }
    //checks cross
    printf("crossTwo : %d\n", crossTwo);
    if (crossTwo == 264 || crossTwo == 237) {
        win = 1;
    }
    return win;
    
}

int main() {
    //instance variables
    char board[SIZE][SIZE] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    //booleans
    int win = 0;
    int misclick = 0;
    //counters
    int turn = 1;
    char let = 'X';
    char row;
    char col;

    printf("x goes first\n");

    //game loop, resolves once there is a winner
    while (win != 1) {
        printBoard(board);
        printf("TURN %d\n", turn);
        printf("Enter row. T, M, B: \n");
        scanf(" %c", &row);
        printf("Enter col. L, M, R: \n");
        scanf(" %c", &col);

        //handles input and places X or O in spot
        switch (row) {
        case 't':
            switch (col) {
                case 'l':
                    if (board[0][0] != 'X' && board[0][0] != 'Y') {
                        board[0][0] = let;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                    break;
                case 'm':
                    if (board[0][1] != 'X' && board[0][1] != 'Y') {
                        board[0][1] = let;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                    break;
                case 'r':
                    if (board[0][2] != 'X' && board[0][2] != 'Y') {
                        board[0][2] = let;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                    break;
                default:
                    printf("error");
                    break;
            }
            break;
        case 'm':
            switch (col) {
                case 'l':
                    if (board[1][0] != 'X' && board[1][0] != 'Y') {
                        board[1][0] = let;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                    break;
                case 'm':
                    if (board[1][1] != 'X' && board[1][1] != 'Y') {
                        board[1][1] = let;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                    break;
                case 'r':
                    if (board[1][2] != 'X' && board[1][2] != 'Y') {
                        board[1][2] = let;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                default:
                    printf("error");
                    break;
            }
            break;
        case 'b':
            switch (col) {
                case 'l':
                    if (board[2][0] != 'X' && board[2][0] != 'Y') {
                        board[2][0] = let;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                case 'm':
                    if (board[2][1] != 'X' && board[2][1] != 'Y') {
                        board[2][1] = let;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                case 'r':
                    if (board[2][2] != 'X' && board[2][2] != 'Y') {
                        board[2][2] = let;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                default:
                    printf("error");
                    break;
            }
            break;
        
        default:
            printf("error");
            break;
        }

        if (misclick == 0) {
            if (let == 'X') {
                let = 'Y';
            } else {
                let = 'X';
            }
            turn++;
            win = checkWin(board);
            printf("win: %d\n", win);
        } else {
            misclick = 0;
        }
    }
    return 0;
}
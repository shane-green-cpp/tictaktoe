#include <stdio.h>
//defining SIZE of array because im trying to prevent error, not sure
//if it does anything though
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

//checkTie
int checkTie(char board[SIZE][SIZE], char nextPlayer) {
    int winnable = 0;
    for (int i = 0; i < SIZE; i++) {
        int r = 0;
        int c = 0;
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == nextPlayer) {
                r++;
            }
            if (board[j][i] == nextPlayer) {
                c++;
            }
        }
        if (r == 0 || c == 0) {
            winnable = 1;
        }
    }
    if (board[0][0] != nextPlayer && board[1][1] != nextPlayer && board[2][2] != nextPlayer) {
        winnable = 1;
    }
    if (board[0][2] != nextPlayer && board[1][1] != nextPlayer && board[2][0] != nextPlayer) {
        winnable = 1;
    }
    return winnable;
}

//function that test if someone has won
int checkWin(char board[SIZE][SIZE], char nextPlayer) {
    int charValRow, charValCol;
    int crossOne = board[0][0]+board[1][1]+board[2][2];
    int crossTwo = board[0][2]+board[1][1]+board[2][0];
    int win = 0;

    //this loop determins if a win has occured, or if is possible
    for (int i = 0; i < 3; i++) {
        charValRow = board[i][0]+board[i][1]+board[i][2];
        charValCol = board[0][i]+board[1][i]+board[2][i];
        int pos = 1;
        if (charValRow == 264 || charValRow == 237) {
            win = 1;
        }
        if (charValCol == 264 || charValCol == 237) {
            win = 1;
        }
    }

    //checks crossOne for win
    printf("crossOne : %d\n", crossOne);
    if (crossOne == 264 || crossOne == 237) {
        win = 1;
    }
    //checks crossTwo for win
    printf("crossTwo : %d\n", crossTwo);
    if (crossTwo == 264 || crossTwo == 237) {
        win = 1;
    }
    
    //check tie
    int tie = checkTie(board, nextPlayer);
    if (tie == 0) {
        if (nextPlayer == 'X') {
            tie = checkTie(board, 'O');
        }
        else {
            tie = checkTie(board, 'X');
        }
    }
    if (tie == 0) {
        printf("\nTIE GAME\n");
        win = 1;
        return win;
    }
    else if (win == 1) {
        printf("\nGAME WON\n");
        return win;
    }
    else {
        printf("\nCONTINUE PLAY\n");
        return win;
    }
    
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
    printBoard(board);
    //game loop, resolves once there is a winner
    while (win != 1) {
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
                        break;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                    break;
                case 'm':
                    if (board[0][1] != 'X' && board[0][1] != 'Y') {
                        board[0][1] = let;
                        break;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                    break;
                case 'r':
                    if (board[0][2] != 'X' && board[0][2] != 'Y') {
                        board[0][2] = let;
                        break;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                    break;
                default:
                    printf("error\n");
                    break;
            }
            break;
        case 'm':
            switch (col) {
                case 'l':
                    if (board[1][0] != 'X' && board[1][0] != 'Y') {
                        board[1][0] = let;
                        break;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                    break;
                case 'm':
                    if (board[1][1] != 'X' && board[1][1] != 'Y') {
                        board[1][1] = let;
                        break;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                    break;
                case 'r':
                    if (board[1][2] != 'X' && board[1][2] != 'Y') {
                        board[1][2] = let;
                        break;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                default:
                    printf("error\n");
                    break;
            }
            break;
        case 'b':
            switch (col) {
                case 'l':
                    if (board[2][0] != 'X' && board[2][0] != 'Y') {
                        board[2][0] = let;
                        break;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                case 'm':
                    if (board[2][1] != 'X' && board[2][1] != 'Y') {
                        board[2][1] = let;
                        break;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                case 'r':
                    if (board[2][2] != 'X' && board[2][2] != 'Y') {
                        board[2][2] = let;
                        break;
                    } else {
                        printf("space taken! try again\n");
                        misclick = 1;
                        break;
                    }
                default:
                    printf("error\n");
                    break;
            }
            break;
        
        default:
            printf("error\n");
            break;
        }

        //sets up turn player for next turn
        if (misclick == 0) {
            if (let == 'X') {
                let = 'O';
            } else {
                let = 'X';
            }
            turn++;
            win = checkWin(board, let);
        } else {
            misclick = 0;
        }
        printBoard(board);
    }
    return 0;
}
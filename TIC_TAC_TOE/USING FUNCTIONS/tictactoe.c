#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
int isFull(char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
    char player = 'x';
    char choice;
    int win = 0, valid, i, j;

    printf("=== TIC TAC TOE ===\n\n");

    while (1) {
        printBoard(board);
        printf("Player %c, choose a position (1-9): ", player);
        scanf(" %c", &choice);

        valid = 0;
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (board[i][j] == choice) {
                    board[i][j] = player;
                    valid = 1;
                    break;
                }
            }
            if (valid) break;
        }

        if (!valid) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        win = checkWin(board);
        if (win) {
            printBoard(board);
            printf("Player %c wins!\n", player);
            break;
        }

        if (isFull(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        // Switch player
        player = (player == 'x') ? '0' : 'x';
    }

    return 0;
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) 
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) 
            printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        // rows and columns
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    // diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

int isFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] != 'x' && board[i][j] != '0')
                return 0;
    return 1;
}


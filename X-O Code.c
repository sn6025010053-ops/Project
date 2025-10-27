#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]); 
int makeMove(char board[3][3], char currentPlayer, int row, int col);
int checkWin(char board[3][3], char currentPlayer);
int checkDraw(char board[3][3]);
char switchPlayer(char currentPlayer); 

int main() {
    char board[3][3];
    char currentPlayer;
    int row, col;
    char playAgain;
    
    printf("=== Welcome to Tic Tac Toe ===\n");
    printf("Enter your move as row and column (1-3)\n");
    do {
        initializeBoard(board);
        currentPlayer = 'X';
        
        // Main Game Loop
        while (1) {
            displayBoard(board);
            
            printf("Player %c's turn\n", currentPlayer);
            
            do {
                printf("Enter row (1-3): ");
                scanf("%d", &row);
                printf("Enter column (1-3): ");
                scanf("%d", &col);
                
                if (!makeMove(board, currentPlayer, row - 1, col -1)) {
                    printf("Invalid input! Please enter a number.\n");
                } else {
                    break;
                }
            } while (1);
            
            // Check For Win or Draw
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                break;
            }
            else if (checkDraw(board)) {
                displayBoard(board);
                printf("It's a draw! Good Game!\n");
                break;
            }
            
            //Switch To The Other Player
            currentPlayer = switchPlayer(currentPlayer);
        }
        printf("Play Again? (y/n): ");
        scanf(" %c", &playAgain);
        
    }
    while (playAgain == 'y' || playAgain == 'Y');
    printf("Thank You For Playing!\n");
    return 0;
}

// === Function Definitions ===
    void initializeBoard(char board[3][3]) {
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }
    
    void displayBoard(char board[3][3]) {
        printf("\n  1  2  3\n");
        for (int i = 0; i < 3; i++) {
            printf("%d ", i + 1);
            for (int j = 0; j < 3; j++) {
                printf("%c", board[i][j]);
                if (j < 2) printf(" | ");
            }
            printf("\n");
            if (i < 2) printf(" -----------\n");
        }
        printf("\n");
    }
    
    int makeMove(char board[3][3], char currentPlayer, int row, int col) {
        if  (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return 0; // Invalid Move
        }
        board[row][col] = currentPlayer;
        return 1; // Valid Move
    }
    
    int checkWin(char board[3][3], char currentPlayer) {
        int i;
        
        // Check Rows
        for (i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return 1;
            }
        }
        
        // Check Columns
        for (i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return 1;
            }
        }
        
        // Check Diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return 1;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return 1;
        }
        
        return 0;
    }
    
    int checkDraw(char board[3][3]) {
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
              if (board[i][j] == ' ') {
                return 0; // Game Not Over  
            }
        }
    }
    return 1; //Draw
}

char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

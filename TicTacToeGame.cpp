#include <iostream>

using namespace std;

// Function to draw the Tic Tac Toe board
void drawBoard(char board[3][3]) {
    cout << "   1   2   3" << endl;
    cout << " -------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " | ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << " -------------" << endl;
    }
}

// Function to check if there is a win
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false; // If there is an empty cell, game is not a draw yet
        }
    }
    return true; // All cells are filled
}

int main() {
    char board[3][3]; // Initialize empty 3x3 board
    char currentPlayer = 'X'; // Player 1 starts with 'X'
    int row, col;

    cout << "Welcome to Tic Tac Toe!" << endl;

    // Initialize the board with empty cells
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }

    // Main game loop
    while (true) {
        // Draw the board
        drawBoard(board);

        // Prompt the current player to make a move
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the input is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Update the board with the player's move
        board[row - 1][col - 1] = currentPlayer;

        // Check for win or draw
        if (checkWin(board, currentPlayer)) {
            drawBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        } else if (checkDraw(board)) {
            drawBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;


void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << "\n---------\n";
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}


void makeMove(vector<vector<char>>& board, int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
    } else {
        cout << "Invalid move. Cell already occupied. Try again.\n";
    }
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    cout << "Welcome to Tic Tac Toe!\n";

    while (true) {
        printBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        row--;
        col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3) {
            makeMove(board, row, col, currentPlayer);


            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }


            if (isBoardFull(board)) {
                printBoard(board);
                cout << "It's a tie!\n";
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Row and column must be between 1 and 3. Try again.\n";
        }
    }

    return 0;
}


#include<bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    // step 1 - initialize boolean arrays to track numbers in rows, columns, and boxes
    bool rows[9][9] = { false };
    bool columns[9][9] = { false };
    bool boxs[9][9] = { false };

    // step 2 - iterate through the board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char num = board[i][j];

            // ignore empty cells
            if (num == '.') continue;

            // step 3 - calculate boxIndex
            int bi = (i / 3) * 3 + (j / 3);

            // get numValue
            int numValue = num - '1';

            // step 4 - check if val already exists in row, col or box
            if (rows[i][numValue] || columns[j][numValue] || boxs[bi][numValue]) {
                return false;
            }

            // step 5 - mark the number as seen in the corresponding row, column, and box
            rows[i][numValue] = true;
            columns[j][numValue] = true;
            boxs[bi][numValue] = true;
        }
    }

    // step 6 - No duplicates found, board is valid so return true
    return true;
}

int main() {
    // vector<vector<char>> board = {
    //         {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    // };

    vector<vector<char>> board = {
        { '8', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };

    bool res = isValidSudoku(board);
    res ? cout << "true" : cout << "false";
    return 0;
}
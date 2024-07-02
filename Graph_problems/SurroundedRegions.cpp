
// Problem link - https://leetcode.com/problems/surrounded-regions/

#include<bits/stdc++.h>
using namespace std;

// helper method to perform BFS traversal
void bfsHelper(vector<vector<char>>& board, int i, int j){
    // find size of rows and columns
    int rows = board.size();
    int cols = board[0].size();

    // using queue of pairs to perform BFS
    queue<pair<int, int>> q;
    // insert border cells(i,j) into queue
    q.push({i, j});
    // mark this cell to avoid revisiting
    board[i][j] = 'M';

    // directions vector to traverse neighbors
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

    // traverse queue to visit border's 0 one by one
    while(!q.empty()){
        // get front cell's cord from queue
        auto [x, y] = q.front();
        q.pop();

        // traverse current cell's neighbors
        for(auto [dx, dy] : directions){
            int nx = x + dx;
            int ny = y + dy;

            // by check border conditions
            if(nx >= 0 && ny >= 0 && nx < rows && ny < cols && board[nx][ny] == 'O'){
                // mark this cell to avoid revisiting
                board[nx][ny] = 'M';
                
                // push neighbor's cell into queue
                q.push({nx, ny});
            }
        }
    }

}

void solve(vector<vector<char>>& board) {
    // cornor case:
    if(board.empty()) return;

    // find size of rows and columns
    int rows = board.size();
    int cols = board[0].size();

    // step1 : Mark all 'O's on the border and their connected 'O's
    for (int i = 0; i < rows; i++) {
        // left border cells
        if (board[i][0] == 'O') bfsHelper(board, i, 0);

        // right border cells
        if (board[i][cols - 1] == 'O') bfsHelper(board, i, cols - 1);
    }

    for (int j = 0; j < cols; j++) {
        // top border cells
        if (board[0][j] == 'O') bfsHelper(board, 0, j);

        // bottom border cells
        if (board[rows - 1][j] == 'O') bfsHelper(board, rows - 1, j);
    }

    // step2 : convert all remaining (that are not border/edge) 'O's to 'X
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }

    // step3: Convert all 'M's back to 'O's
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'M') {
                board[i][j] = 'O';
            }
        }
    }
}

int main(){
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    solve(board);

    // Print the board
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    
    return 0;
}
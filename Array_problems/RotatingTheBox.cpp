
// Problem link - https://leetcode.com/problems/rotating-the-box/?envType=daily-question&envId=2026-05-06

#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> rotateTheBox1(vector<vector<char>>& boxGrid) {
    // find row and column size
    int m = boxGrid.size();
    int n = boxGrid[0].size();

    // step 1 - find transpose of a given boxGrid
    vector<vector<char>> res(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            res[i][j] = boxGrid[j][i];
        }
    }

    // step 2 - for 90 degree rotation, reverse each row
    for(vector<char>& row : res){
        reverse(begin(row), end(row));
    }

    // step 3 - apply gravity effect
    for(int j=0; j<m; j++){
        for(int i=n-1; i>=0; i--){
            if(res[i][j] == '.'){
                // if it is space then shift stone
                int stoneRow = -1;

                for(int k=i-1; k>=0; k--){
                    if(res[k][j] == '*'){
                        // incase of obstacle break
                        break;
                    }
                    else if(res[k][j] == '#'){
                        stoneRow = k;
                        break;
                    }
                }

                if(stoneRow != -1){
                    res[i][j] = '#';
                    res[stoneRow][j] = '.';
                }
            }
        }
    }

    // step 4 - return final result, `res`
    return res;
}

vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
    // find row and column size
    int m = boxGrid.size();
    int n = boxGrid[0].size();

    // step 1 - find transpose of a given boxGrid
    vector<vector<char>> res(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            res[i][j] = boxGrid[j][i];
        }
    }

    // step 2 - for 90 degree rotation, reverse each row
    for(vector<char>& row : res){
        reverse(begin(row), end(row));
    }

    // step 3 - apply gravity effect
    for(int j=0; j<m; j++){
        int spaceBottomRow = n-1;
        for(int i=n-1; i>=0; i--){
            if(res[i][j] == '*'){
                // incase of obstacle update space bottom row
                spaceBottomRow = i-1;
                continue;
            }

            if(res[i][j] == '#'){
                // incase of stone , shift it to required place
                res[i][j] = '.';
                res[spaceBottomRow][j] = '#';
                spaceBottomRow--;
            }
        }
    }

    // step 4 - return final result, `res`
    return res;
}


void print2DVector(vector<vector<char>>& matrix){
    cout << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < matrix.size() - 1) cout << ",";
    }
    cout << "]" << std::endl;
}

int main(){
    // vector<vector<char>> boxGrid = {{'#','.','#'}};

    vector<vector<char>> boxGrid = {{'#','.','*','.'},{'#','#','*','.'}};
    vector<vector<char>> res = rotateTheBox(boxGrid);
    print2DVector(res);
    return 0;
}
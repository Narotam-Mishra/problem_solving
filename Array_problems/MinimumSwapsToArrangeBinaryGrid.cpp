
// Problem link - https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/

#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<vector<int>>& grid) {
    int n = grid.size();

    // step 1 - find trailing zeros for each row
    vector<int> trailingZeros(n, 0);
    for(int i=0; i<n; i++){
        // start from end
        int j = n-1;

        int count = 0;
        while(j >= 0 && grid[i][j] == 0){
            count++;
            j--;
        }

        // store trailing zeros
        trailingZeros[i] = count;
    }

    // step 2 - for each row check 
    // no of zeroes needed
    int steps = 0;
    for(int i=0; i<n; i++){
        int req = n-i-1;

        int j = i;
        while(j < n && trailingZeros[j] < req){
            j++;
        }

        // edge case
        if(j == n){ 
            return -1;
        }

        steps += j - i;

        while(j > i){
            swap(trailingZeros[j], trailingZeros[j-1]);
            j--;
        }
    }

    // step 3 - return minimum steps
    return steps;
}

int main(){
    // vector<vector<int>> grid = {{0,0,1},{1,1,0},{1,0,0}};

    // vector<vector<int>> grid = {{0,1,1,0},{0,1,1,0},{0,1,1,0},{0,1,1,0}};

    vector<vector<int>> grid = {{1,0,0},{1,1,0},{1,1,1}};
    cout<<minSwaps(grid);
    return 0;
}
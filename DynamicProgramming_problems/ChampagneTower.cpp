
// Problem link - https://leetcode.com/problems/champagne-tower/description/?envType=daily-question&envId=2026-02-14

#include<bits/stdc++.h>
using namespace std;

// array to memoize
double memo[101][101];

double solveRec(int poured, int i, int j){
    // base case: invalid glass posiiton
    if(i<0 || j<0 || i<j){
        return 0.0;
    }

    // check if we reached the top
    if(i == 0 && j == 0){
        // then return poured
        return poured;
    }

    // if ans is already computed then return it
    if(memo[i][j] != -1){
        return memo[i][j];
    }

    // recursive case: recusively compute for top left
    double left_up = (solveRec(poured, i-1,j-1) - 1)/2.0;
    // recusively compute for top right
    double right_up = (solveRec(poured, i-1, j) - 1)/2.0;

    // check if parent had ≤ 1 cup, no overflow
    if(left_up < 0) left_up=0.0;
    if(right_up < 0) right_up = 0.0;

    // total champagne reaching this glass
    return memo[i][j] = left_up + right_up;
}

double champagneTower(int poured, int query_row, int query_glass) {
    // initialize memo
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            memo[i][j] = -1;
        }
    }

    // step 1 - solve recursilvely and return
    return min(1.0, solveRec(poured, query_row, query_glass));
}

int main(){
    // int poured = 1, query_row = 1, query_glass = 1;

    // int poured = 2, query_row = 1, query_glass = 1;

    int poured = 100000009, query_row = 33, query_glass = 17;
    cout<<champagneTower(poured, query_row, query_glass);
    return 0;
}
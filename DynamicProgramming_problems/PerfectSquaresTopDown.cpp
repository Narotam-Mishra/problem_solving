
// Problem link - https://leetcode.com/problems/perfect-squares/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<int> sqArr;

int PerfectSquaresTopDownDP(int num){
    // Base case: if num is 0 return 0
    if(num == 0) return 0;

    // if dp[num] is already calculated then return its value
    if(dp[num] != -1) return dp[num];

    int ans = numeric_limits<int>::max();

    for(int i=0; i<sqArr.size(); i++){
        if(num >= sqArr[i]){
            ans = min(ans, PerfectSquaresTopDownDP(num - sqArr[i]));
        }
    }

    return dp[num] = 1 + ans;
}

int numSquares(int n) {
    sqArr.resize(100);
    int j = 0;

    for(int i=1; i*i<=10000; i++){
        sqArr[j++] = i*i;
    }

    dp.assign(n+1, -1);
    return PerfectSquaresTopDownDP(n);
}

int main(){
    int num = 12;
    cout<<numSquares(num)<<endl;
    return 0;
}
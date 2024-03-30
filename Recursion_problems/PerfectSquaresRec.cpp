
// Problem link - https://leetcode.com/problems/perfect-squares/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> sqArr;

int PerfectSquaresRecursive(int num){
    if(num == 0) return 0;

    int ans = numeric_limits<int>::max();

    for(int i=1; i<sqArr.size(); i++){
        if(num >= sqArr[i]){
            ans = min(ans, PerfectSquaresRecursive(num - sqArr[i]));
        }
    }

    return 1 + ans;
}

int numSquares(int n) {
    sqArr.resize(n+1);
    for(int i=1; i<=n; i++){
        sqArr[i] = i*i;
    }
    int res = PerfectSquaresRecursive(n);
    return res;
}

int main(){
    int n = 13;
    cout<<numSquares(n)<<endl;
    return 0;
}
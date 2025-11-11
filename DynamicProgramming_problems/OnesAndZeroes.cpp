
// Problem link - https://leetcode.com/problems/ones-and-zeroes/description/?envType=daily-question&envId=2025-11-11

#include<bits/stdc++.h>
using namespace std;

int memo[101][101][601];

int solve(vector<pair<int, int>>& countPairs, int m, int n, int i){
    // base case:
    if(i >= countPairs.size() || (m == 0 && n == 0)){
        return 0;
    }

    // if answer is already computed then return it
    if(memo[m][n][i] != -1){
        return memo[m][n][i];
    }

    // two choices in recursion
    // option 1 - take 0s & 1s
    int take = 0;
    if(countPairs[i].first <= m && countPairs[i].second <= n){
        take = 1 + solve(countPairs, m - countPairs[i].first, n - countPairs[i].second, i+1);
    }

    // option 2 - skip Os and 1s
    int skip = solve(countPairs, m, n, i+1);

    // memoize and return maximum of take and skipß
    return memo[m][n][i] = max(take, skip);
}

int findMaxForm(vector<string>& strs, int m, int n) {
    int N = strs.size();

    // step 1 - find count of zeros and ones in vector of pairs
    vector<pair<int, int>> countPairs(N);
    for(int i=0; i<N; i++){
        int zeros = 0, ones = 0;

        for(const char& ch : strs[i]){
            if(ch == '0'){
                zeros++;
            }else{
                ones++;
            }

            countPairs[i] = {zeros, ones};
        }
    }

    // initialize values in memo with -1
    memset(memo, -1, sizeof(memo));

    // step 2 - solve the problem recursively and retun result
    return solve(countPairs, m, n, 0);
}

int main(){
    vector<string> strs = {"10","0001","111001","1","0"};
    int m = 5, n = 3;

    // vector<string> strs = {"10","0","1"};
    // int m = 1, n = 1;
    cout<<findMaxForm(strs, m ,n);
    return 0;
}
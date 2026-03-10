
// Problem link - https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/description/?envType=daily-question&envId=2026-03-10

#include<bits/stdc++.h>
using namespace std;

int numberOfStableArrays(int zero, int one, int limit) {
    const int mod = 1e9 + 7;

    // dp[i][j][k] where:
    // i = count of zeros used (0 to zero)
    // j = count of ones used (0 to one)
    // k = 0 if last digit is 0, 1 if last digit is 1
    vector<vector<vector<int>>> dp(zero+1, vector<vector<int>>(one + 1, vector<int>(2, 0)));

    // Base case: arrays with only zeros (last digit is 0)
    for(int i=1; i<=min(zero, limit); i++){
        dp[i][0][0] = 1;
    }

    // Base case: arrays with only ones (last digit is 1)
    for(int j=1; j<=min(one, limit); j++){
        dp[0][j][1] = 1;
    }

    // Fill DP table
    for(int i=0; i<=zero; i++){
        for(int j=0; j<=one; j++){
            if(i == 0 || j == 0) continue;
            
            // Add one: sum of all valid states ending with 0
            if(j > 0){
                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1]) % mod;
                
                // Subtract invalid states: more than 'limit' consecutive ones
                if(j-1 >= limit){
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j-1-limit][0] + mod) % mod;
                }
            }
            
            // Add zero: sum of all valid states ending with 1
            if(i > 0){
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % mod;
                
                // Subtract invalid states: more than 'limit' consecutive zeros
                if(i-1 >= limit){
                    dp[i][j][0] = (dp[i][j][0] - dp[i-1-limit][j][1] + mod) % mod;
                }
            }
        }
    }

    return (dp[zero][one][0] + dp[zero][one][1]) % mod;
}

int main(){
    int zero = 3, one = 3, limit = 2;
    cout<<numberOfStableArrays(zero, one, limit);
    return 0;
}
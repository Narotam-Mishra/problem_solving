
// Problem link - https://leetcode.com/problems/delete-columns-to-make-sorted-iii/?envType=daily-question&envId=2025-12-22

#include<bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string>& strs) {
    // get rows and columns count
    int r = strs.size();
    int c = strs[0].size();

    // dp[i] = length of the longest valid column sequence ending at column `i`
    vector<int> dp(c, 1);

    // keep track of maximum LIS length found so far
    int lis = 0;

    // step 1 - using Longest Increasing Subsequence technique
    for(int i=0; i<c; i++){
        for(int j=0; j<i; j++){
            // flag to check if LIS condition hold true for all strings
            bool isValid = true;

            // step 2 - check for all strings (row wise)
            for(int k=0; k<r; k++){
                // check if column j can come before column i
                if(strs[k][j] > strs[k][i]){
                    isValid = false;
                    break;
                }
            }

            // if valid, update dp[i]
            if(isValid){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        
        // step 3 - update LIS length
        lis = max(lis, dp[i]);
    }

    // step 4 - return minimum deletion required
    return c - lis;
}

int main(){
    // vector<string> strs = {"babca", "bbazb"};

    // vector<string> strs = {"edcba"};

    vector<string> strs = {"ghi","def","abc"};
    cout<<minDeletionSize(strs);
    return 0;
} 
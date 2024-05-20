
#include<bits/stdc++.h>
using namespace std;

vector<int> pArr;
int dp[1005][105][2];

int findMaxProfitRec(int i, int k, int ts){
    // Base case: all days are completed
    if(i == pArr.size()) return 0;

    // if dp[i][k][ts] is already computed then return dp[i][k][ts]
    if(dp[i][k][ts] != -1) return dp[i][k][ts];

    int ans = -1;

    // Recursive case:
    // Case 1: Ignore stock
    ans = max(ans, findMaxProfitRec(i+1, k, ts));

    // Case 2: Buy the stock on ith day
    if(k > 0 && ts == 0){
        ans = max(ans, -pArr[i] + findMaxProfitRec(i+1, k, 1));
    }

    // Case 3: sell the stock on ith day
    if(ts == 1){
        ans = max(ans, pArr[i] + findMaxProfitRec(i+1, k-1, 0));
    }

    return dp[i][k][ts] = ans;
}

int maxProfit(int k, vector<int>& prices) {
    pArr = prices;
    for(int i=0; i<1005; i++){
        for(int j=0; j<105; j++){
            for(int l=0; l<2; l++){
                dp[i][j][l] = -1;
            }
        }
    }
    return findMaxProfitRec(0, k, 0);
}

int main(){
    int k = 2;
    vector<int> prices = {3,2,6,5,0,3};
    cout<<maxProfit(k, prices)<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
    // step 1 - create dp array of boolean
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));

    // step 2 - iterate on dp table and fill it required value
    int mr = dp.size()-1;
    int mc = dp[0].size()-1;

    for(int i=0; i<=mr; i++){
        for(int j=0; j<=mc; j++){
            if(i == 0 && j == 0){
                dp[i][j] = true;
            }else if(j == 0){
                dp[i][j] = false;
            }else if(i == 0){
                char chp = p[j - 1];
                if(chp == '*'){
                    dp[i][j] = dp[i][j-2];
                }else{
                    dp[i][j] = false;
                }
            }else{
                char chp = p[j-1];
                char chs = s[i-1];

                if(chp == '*'){
                    dp[i][j] = dp[i][j-2];

                    char chpprev = p[j-2];
                    if(chpprev == '.' || chpprev == chs) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }else if(chp == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(chp == chs){ 
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
    }

    // step 3 - return final output 
    return dp[mr][mc];
}

int main(){
    string s = "aa", p = "a";

    // string s = "aa", p = "a*";

    // string s = "ab", p = ".*";
    bool res = isMatch(s, p);
    res ? cout<<"true":cout<<"false";
    return 0;
}

// Problem link - https://leetcode.com/problems/number-of-substrings-with-only-1s/description/?envType=daily-question&envId=2025-11-16

#include<bits/stdc++.h>
using namespace std;

int numSub1(string s) {
    const int mod = 1e9 + 7;

    // store final result in res
    int res = 0;

    // step 1 - iterate on each character of s
    int count = 0;
    for(auto& ch : s){
        // step 2 - count ones in current subsring
        if(ch == '1'){
            count++;
        }else{
            // step 3 - calculate number of substring possible
            res = (res + ((long long) count * (count + 1)) / 2) % mod;

            // step 4 - reset count of ones to 0 as streak of 1s break
            count = 0;
        }
    }

    // step 5 - calculate number of substring for last substring if exist
    if(count > 0){
        res = (res + ((long long) count * (count + 1)) / 2) % mod;
    }

    // step 6 - return final result, res
    return res;
}

int numSub(string s){
    const int mod = 1e9 + 7;

    // store final result in res
    int res = 0;

    // step 1 - iterate on each substring of s
    int c = 0;
    for(auto& ch : s){
        // step 2 - count ones in each substring
        if(ch == '1'){
            c++;

            // calculate number of substring with 1s only
            res = (res + c) % mod;
        }else{
            // step 3 - reset count, c to 0 as 1s streaks break
            c = 0;
        }
    }

    // step 4 - return final result, res
    return res;
}

int main(){
    // string s = "0110111";

    // string s = "101";

    string s = "111111";
    cout<<numSub(s);
    return 0;
}

// Problem link - https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

bool digitCount(string num) {
    // step 1 - create frquency array map 
    vector<int> freq(10,0);
    int n = num.size();
    for(char digit : num){
        freq[digit - '0']++;
    }

    // step 2 -  check if each index i occurs num[i] times
    for(int i=0; i<n; i++){
        if(freq[i] != (num[i] - '0')){
            // found mismatch, so return false
            return false;
        }
    }

    // step 3 - all checks passed
    return true;
}

int main(){
    // string num = "1210";

    string num = "030";
    bool res = digitCount(num);
    res ? cout<<"true" : cout<<"false";
    return 0;
}
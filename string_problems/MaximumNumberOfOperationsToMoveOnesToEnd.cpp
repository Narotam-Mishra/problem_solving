
// Problem link - https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/?envType=daily-question&envId=2025-11-13

#include<bits/stdc++.h>
using namespace std;

int maxOperations(string s) {
    int n = s.length();

    int ops = 0;

    // step 1 - whenever we ecounter 0, find operations
    // operation will count of 1 seen so far, ops += count1
    int c1 = 0, i=0;
    while(i < n){
        if(s[i] == '0'){
            ops += c1;

            // step 2 - move till first 1 or occurence
            while(i < n && s[i] == '0'){
                i++;
            }
        }else{
            // step 3 - check if s[i] is still '1'
            // continue incrementing count of 1
            c1++;
            i++;
        }
    } 

    // step 4 - return the maximum number of operations 
    return ops;
}

int main(){
    // string s = "1001101";

    string s = "00111";
    cout<<maxOperations(s);
    return 0;
}
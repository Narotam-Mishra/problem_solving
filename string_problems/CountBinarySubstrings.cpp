
// Problem link - https://leetcode.com/problems/count-binary-substrings/description/?envType=daily-question&envId=2026-02-19

#include<bits/stdc++.h>
using namespace std;

int countBinarySubstrings1(string s) {
    // step 1 - variable intialization
    int prevGroup = 0, currGroup = 1, count = 0;

    // step 2 - iterate on input string
    for(int i=1; i<s.size(); i++){
        if(s[i] == s[i-1]){
            // extend current group if current and previous digits are equal
            currGroup++;
        }else{
            // otherwise count valid substring
            count += min(currGroup, prevGroup);

            // move to new group
            prevGroup = currGroup;

            // reset counter for the new group
            currGroup = 1;
        }
    }

    // step 3 - count last valid substring
    return count + min(currGroup, prevGroup);
}

int countBinarySubstrings(string s) {
    int n = s.length();

    // keep track of ccurrent and previous consective streak count
    int currCnt=1, prevCnt = 0;

    // step 1 - iterate on each character of string
    int res = 0;
    for(int i=1; i<n; i++){
        // step 2 - extend current group if current and previous digits are equal
        if(s[i] == s[i-1]){
            currCnt++;
        }else{
            // step 3 - otherwise count valid substring
            res += min(currCnt, prevCnt);

            // step 4 - move to new group
            prevCnt = currCnt;

            // step 5 - reset counter for the new group
            currCnt = 1;
        }
    }

    // step 6 - count last valid substring and return result, `res`
    return res + min(currCnt, prevCnt);
}

int main(){
    // string s = "00110011";

    string s = "10101";
    cout<<countBinarySubstrings(s)<<endl;
    return 0;
}
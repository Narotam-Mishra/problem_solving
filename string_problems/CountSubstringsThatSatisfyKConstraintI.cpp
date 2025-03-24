
// Problem link - https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int countKConstraintSubstrings(string s, int k) {
    // step 1 - initialize count to count number of substring that satisfy k-constraint
    int count = 0;

    // step 2 - iterate on input string `s`
    for(int i=0; i<s.size(); i++){
        int zeroCount = 0, oneCount = 0;

        // step 3 - iterate on each substring
        for(int j=i; j<s.size(); j++){
            // update 0's and 1's count
            if(s[j] == '0') zeroCount++;
            else oneCount++;

            // step 4 - check k-constraint
            if(zeroCount <= k || oneCount <= k){
                count++;
            }
        }
    }

    // step 5 - return count
    return count;
}

int main(){
    // string s = "10101";
    // int k = 1;

    // string s = "1010101";
    // int k = 2;

    string s = "11111";
    int k = 1;
    cout<<countKConstraintSubstrings(s,k)<<endl;
    return 0;
}
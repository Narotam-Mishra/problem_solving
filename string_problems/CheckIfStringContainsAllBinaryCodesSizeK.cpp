
// Problem link - https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/?envType=daily-question&envId=2026-02-23

#include<bits/stdc++.h>
using namespace std;

bool hasAllCodes(string s, int k) {
    int n = s.length();

    // store unique codes of k length
    unordered_set<string> seen;

    // step 1 - iterate on binary string
    int codes = (1 << k);
    for(int i=k; i<=n; i++){
        // step 2 - find code of length k
        string sub = s.substr(i-k, k);

        // step 3 - check in set 
        if(!seen.count(sub)){
            seen.insert(sub);
            codes--;
        }

        // step 4 - check all codes has been check
        if(codes == 0){
            // then return true immediately
            return true;
        }
    }

    // step 5 - otherwise return false
    return false;
}

int main(){
    // string s = "00110110";
    // int k = 2;

    // string s = "0110";
    // int k = 1;

    string s = "0110";
    int k = 2;
    bool res = hasAllCodes(s, k);
    res ? cout<<"true" : cout<<"false";
    return 0;
}
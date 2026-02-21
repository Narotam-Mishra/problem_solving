
// Problem link - https://leetcode.com/problems/special-binary-string/description/?envType=daily-question&envId=2026-02-20

#include<bits/stdc++.h>
using namespace std;

string solveRec(string& s){
    // store all top-level special substrings
    vector<string> specialStrs;

    // keep track of sum
    int sum = 0;

    // keep track of starting index of current substring
    int start = 0;

    // step 1 - iterate string, `s` 
    for(int i=0; i<s.length(); i++){
        // update sum
        sum += s[i] == '1' ? 1 : -1;

        // step 2 - check if sum is 0
        // then we found one complete substring
        if(sum == 0){
            // extract the inner portion (excluding outer 1 and 0)
            // because special string structure is: 1 + (special inner) + 0
            string inner = s.substr(start+1, i-start-1);

            // step 3 - recursively process inner substring
            specialStrs.push_back("1" + solveRec(inner) + "0");
            
            // move start to next segment
            start = i+1;
        }
    }

    // step 4 - sort all top-level special substrings
    sort(specialStrs.begin(), specialStrs.end(), greater<string>());

    // step 5 - concatenate all sorted substrings
    string res;
    for(string &str : specialStrs){
        res += str;
    }

    // return final result, `res`
    return res;
}

string makeLargestSpecial(string s) {
    // step 1 - solve recursilvely and return result
    return solveRec(s);
}

int main(){
    // string s = "11011000";

    string s = "10";
    cout<<makeLargestSpecial(s);
    return 0;
}
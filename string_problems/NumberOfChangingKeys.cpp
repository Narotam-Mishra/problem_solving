
// Problem link - https://leetcode.com/problems/number-of-changing-keys/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int countKeyChanges(string s) {
    // step 1 - initialize count
    int count = 0;

    // step 2 - change input string `s` to lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // step 3 - iterate on each character of `s`
    for(int i=1; i<s.size(); i++){
        // get current character of string
        char ch = s[i];

        // step 4 - check if current current is not equals to previous then increment counter
        if(ch != s[i-1]){
            count++;
        }
    }

    // step 5 - return count
    return count;
}

int main(){
    // string s = "aAbBcC";

    string s = "AaAaAaaA";
    cout<<countKeyChanges(s)<<endl;
    return 0;
}
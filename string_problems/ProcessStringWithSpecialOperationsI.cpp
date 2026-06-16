
// Problem link - https://leetcode.com/problems/process-string-with-special-operations-i/description/?envType=daily-question&envId=2026-06-16

#include<bits/stdc++.h>
using namespace std;

string processStr(string s) {
    // keep track of final resultant string, `res`
    string res = "";

    // step 1 - iterate on each character of `s`
    for(char ch : s){
        // step 2 - perform simulation 
        if(ch>='a' && ch<='z'){
            res.push_back(ch);
        }else if(ch == '*'){
            if(res.size() >= 1){
                res.pop_back();
            }
        }else if(ch == '#'){
            string temp = res;
            res += temp;
        }else{
            reverse(res.begin(), res.end());
        }
    }

    // step 3 - return final result, `res`
    return res;
}

int main(){
    // string s = "a#b%*";

    string s = "z*#";
    cout<<processStr(s);
    return 0;
}

// Problem link - https://leetcode.com/problems/faulty-keyboard/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string finalString(string s) {
    // step - 1 - store final string to screen
    string res;

    // step - 2 - loop through each character typed  on character
    for(char ch : s){
        if(ch == 'i'){
            reverse(res.begin(), res.end());
        }else{
            // step 4 - normal behaviour : add character to screen
            res.push_back(ch);
        }
    }

    // step 5 - return final answer string
    return res;
}

int main(){
    // string s = "string";

    string s = "poiinter";
    cout<<finalString(s)<<endl;
    return 0;
}
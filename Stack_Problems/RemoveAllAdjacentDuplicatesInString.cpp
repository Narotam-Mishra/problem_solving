
// Problem link - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if(!st.empty() && st.top() == ch){
            // if current character of string is equal to stack's top then pop from stack
            st.pop();
        }else{
            // otherwise push current character of string into string
            st.push(s[i]);
        }
    }

    //Build the resulting string from the characters in the stack
    string res;
    while (!st.empty()){
        res = st.top() + res;
        st.pop();
    }
    // return result string 'res'
    return res;
}

int main(){
    string str = "abbaca";
    cout<<removeDuplicates(str)<<endl; // Expected output: "ca"
    return 0;
}
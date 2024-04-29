
// Problem link - https://leetcode.com/problems/backspace-string-compare/description/

#include<bits/stdc++.h>
using namespace std;

bool backspaceCompare(string s, string t) {
    // used two stacks to manage strings s & t
    stack<char> st1, st2;

    // iterate string s
    for(int i=0; i<s.size(); i++){
        // if current character is not '#' then push it into stack st1
        if(s[i] != '#'){
            st1.push(s[i]);
        }else{
            // otherwise pop it from stack st1
            if(st1.size() > 0) st1.pop();
        }
    }

    // iterate string t
    for(int i=0; i<t.size(); i++){
        // if current character is not '#' then push it into stack st2
        if(t[i] != '#'){
            st2.push(t[i]);
        }else{
            // otherwise pop it from stack st1
            if(st2.size() > 0) st2.pop();
        }
    }

    // compare both strings using stack top
    while(st1.size() > 0 && st2.size() > 0){
        if(st1.top() != st2.top()) return false;
        st1.pop();
        st2.pop();
    }

    // if both stacks are empty that means both strings are equal 
    // return true
    return (st1.size() == 0 && st2.size() == 0);
}

int main(){
    string s = "ab#c", t = "ad#c";
    cout<<backspaceCompare(s, t)<<endl;
    return 0;
}
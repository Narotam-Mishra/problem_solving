
#include<bits/stdc++.h>
using namespace std;

string clearDigits(string s) {
    // step 1 - intialize stack to store each non-digit
    stack<char> st;

    // step 2 -iterate on each character of input string `s`
    for(char ch : s){
        // step 3 - check if it is digit, remove the closest non-digit from stack
        if(isdigit(ch)){
            // remove the closest non-digit character from stack
            if(!st.empty()){
                st.pop();
            }
        }else{
            // step 4 - push non-digit characters onto the stack
            st.push(ch);
        }
    }

    // step 5 - construct the resulting string from stack
    string res;
    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }

    // step 6 - return res;
    return res;
}

int main(){
    // string s = "abc";

    string s = "cb34";
    cout<<clearDigits(s)<<endl;
    return 0;
}
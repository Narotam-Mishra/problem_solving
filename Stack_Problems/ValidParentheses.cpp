
#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        char curChar = s[i];
        // if current character is opening parentheses, then push into stack
        if (curChar == '(' || curChar == '{' || curChar == '[') {
            st.push(curChar);
        }
        else {
            // if stack is empty, then return false
            if (st.empty()) return false;
            // Pop the top element from the stack
            char chTop = st.top();
            st.pop();
            // Check if the current closing bracket matches the last opening bracket
            if ((curChar == ')' && chTop != '(') || (curChar == '}' && chTop != '{') || (curChar == ']' && chTop != '[')) {
                // if any of above conditions match then return false
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    // string str = "()[]{}";

    string str = "(]";
    cout<<isValid(str)<<endl;
    return 0;
}
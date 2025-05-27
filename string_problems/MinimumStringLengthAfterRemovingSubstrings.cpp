
// Problem link - https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int minLength(string s) {
    // step 1 - uing stack to perform string operation
    stack<char> stack;

    for (char ch : s) {
        // step 2 - iterate on each chacter of `s`
        if (!stack.empty()) {
            char top = stack.top();
            // step 3 - if top + char form "AB" or "CD", then remove them, (pop top, skip char
            if ((top == 'A' && ch == 'B') || (top == 'C' && ch == 'D')) {
                stack.pop(); // Remove the pair
                continue;
            }
        }

        // step 4 - no pair formed, keep the character
        stack.push(ch); // No match, push character
    }

    // step 5 - remaining length after all removal
    return stack.size(); 
}

int main(){
    // string s = "ABFCACDB";

    string s = "ACBBD";
    cout<<minLength(s)<<endl;
    return 0;
}
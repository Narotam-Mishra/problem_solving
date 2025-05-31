
// Problem link - https://leetcode.com/problems/remove-duplicate-letters/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s) {
    // step 1 - count frequency of each letter of `s`
    vector<int> count(26, 0);
    for (char ch : s) {
        count[ch - 'a']++;
    }

    // step 2 - initialize data structures
    // build resultant string from stack
    stack<char> stack;

    // track which character is already in resultant string
    vector<bool> seen(26, false);

    // step 3 - iterate on each character of `s`
    for (char ch : s) {
        // decrease count since we are processing this occurrence
        count[ch - 'a']--;

        // step 4 - if current charcter `ch` already exist in seen then skip it
        if (seen[ch - 'a']) {
            continue;
        }

        // current character `char` is smaller than stack top (for lexicographical order)
        // Stack top appears later in string (count > 0)
        // step 5 - this step ensures we always make the lexicographically smallest choice possible
        while (!stack.empty() && stack.top() > ch && count[stack.top() - 'a'] > 0) {
            char removed = stack.top();
            stack.pop();
            seen[removed - 'a'] = false;
        }

        // step 6 - add current character `ch` to resultant stack and mark true in seen array
        stack.push(ch);
        seen[ch - 'a'] = true;
    }

    // step 7 - build resultant string `res` from stack and return it
    string res = "";
    while (!stack.empty()) {
        res = stack.top() + res;
        stack.pop();
    }

    return res;
}

int main(){
    // string s = "bcabc";

    string s = "cbacdcbc";
    cout<<removeDuplicateLetters(s)<<endl;
    return 0;
}
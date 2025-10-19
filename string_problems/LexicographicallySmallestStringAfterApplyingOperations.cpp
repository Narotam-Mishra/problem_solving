
// Problem link - https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/?envType=daily-question&envId=2025-10-19

#include<bits/stdc++.h>
using namespace std;

// utility function to rotate string `b` steps
void rotateString(string &str, int b){
    reverse(begin(str), end(str));
    reverse(begin(str), begin(str) + b);
    reverse(begin(str) + b, end(str));
}

string findLexSmallestString(string s, int a, int b) {
    // initialize resultant string `res` with the original string
    string res = s;

    // Use BFS to explore all possible string states
    queue<string> q;
    unordered_set<string> visited;

    // step 1 - start BFS from the original string
    q.push(s);
    visited.insert(s);

    while(!q.empty()){
        // step 2 - get current string state from queue
        string currStr = q.front();
        q.pop();

        // step 3 - update result `res` if current string is lexicographically smaller
        if(currStr < res){
            res = currStr;
        }

        // operation 1 - perform add operation
        string temp = currStr;
        for(int i=1; i<temp.length(); i+=2){
            // add 'a' to digit at odd index and cycle back using modulo 10
            temp[i] = ((temp[i] - '0' + a) % 10) + '0';
        }

        // step 5 - if this state hasn't been visited, add to queue for exploration
        if(!visited.count(temp)){
            visited.insert(temp);
            q.push(temp);
        }
        

        // operation 2 - rotate operation - roate right by `b`
        rotateString(currStr, b);
        
        // step 5 - if this state hasn't been visited, add to queue for exploration
        if(!visited.count(currStr)){
            visited.insert(currStr);
            q.push(currStr);
        }
    }

    // step 6 - return final result `res`
    return res;
}

int main(){
    // string s = "5525";
    // int a = 9, b = 2;

    // string s = "74";
    // int a = 5, b = 1;

    string s = "0011";
    int a = 4, b = 2;
    cout<<findLexSmallestString(s, a, b);
    return 0;
}
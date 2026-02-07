
// Problem link - https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/?envType=daily-question&envId=2026-02-07

#include<bits/stdc++.h>
using namespace std;

int minimumDeletions1(string s) {
    // keep track of deletion count
    int deletionCount = 0;

    // using stack based approach to perform simulation
    stack<char> st;

    // step 1 - iterate on each character of input string
    for(char ch : s){
        // step 2 - if stack is empty push character into it
        if(st.empty()){
            st.push(ch);
        }

        // step 3 - check if current char is 'a' and top of stack is 'b'
        else if(ch == 'a' && st.top() == 'b'){
            // it means we found invalid pair(`b` before `a`)
            // so perform deletion
            deletionCount++;

            // and remove `b` from stack to break pair
            st.pop();
        }

        // step 4 - otherwise it's valid situation
        // (`a` after `a`) or (`b` after `a`) or (`b` after `b`)
        else{
            // so push into stack
            st.push(ch);
        }
    }

    // step 5 - return minimum deletion required to balance
    return deletionCount;
}

int minimumDeletions(string s) {
    int n = s.length();

    // keep track of count left 'b' and right 'a' for each character
    vector<int> leftB(n, 0), rightA(n, 0);

    // step 1 - find 'b' count for each character on left
    int bCount = 0;
    for(int i=0; i<n; i++){
        leftB[i] = bCount;
        if(s[i] == 'b'){
            bCount++;
        }
    }

    // step 2 - find 'a' count for each character on right
    int aCount = 0;
    for(int i=n-1; i>=0; i--){
        rightA[i] = aCount;
        if(s[i] == 'a'){
            aCount++;
        }
    }

    // step 3 - find minimum deletion required to balance
    int deletionCount = INT_MAX;
    for(int i=0; i<n; i++){
        deletionCount = min(deletionCount, leftB[i] + rightA[i]);
    }

    // step 4 - return minimum deletion count
    return deletionCount;
}

int main(){
    string s = "aababbab";

    // string s = "bbaaaaabb";
    cout<<minimumDeletions(s);
    return 0;
}
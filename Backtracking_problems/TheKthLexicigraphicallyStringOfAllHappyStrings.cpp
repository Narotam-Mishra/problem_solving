
// Problem link - https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2026-03-14

#include<bits/stdc++.h>
using namespace std;

void solveRec(string& curr, vector<string>& res, int n){
    // base case:
    if(curr.length() == n){
        res.push_back(curr);
        return;
    }

    // backtracking
    for(char ch='a'; ch<='c'; ch++){
        if (!curr.empty() && curr.back() == ch) continue;
        // do
        curr.push_back(ch);

        // explore
        solveRec(curr, res, n);

        // undo
        curr.pop_back();
    }
}

string getHappyString(int n, int k) {
    string curr = "";
    vector<string> res;
    solveRec(curr, res, n);
    if(k > res.size()) return "";
    return res[k-1];
}

int main(){
    // int n = 1, k = 3;

    // int n = 3, k = 9;

    int n = 1, k = 4;
    cout<<getHappyString(n, k);
    return 0;
}
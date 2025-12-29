
// Problem link - https://leetcode.com/problems/pyramid-transition-matrix/?envType=daily-question&envId=2025-12-29

#include<bits/stdc++.h>
using namespace std;

// for memoization
unordered_map<string, bool> memo;

bool solveRec(string curr, unordered_map<string, vector<char>>& mp, int idx, string aboveStr){
    // create unique key for memoization
    string key = curr + "_" + to_string(idx) + "_" + aboveStr;

    // base case: if only one block remains, pyramid is successfully built
    if(curr.length() == 1){
        // reached top
        return memo[key] = true;
    }

    // check if this state is already computed, return stored result
    if(memo.count(key)){
        return memo[key];
    }

    // Recursive case: move to next row
    if(idx == curr.length() - 1){
        return memo[key] = solveRec(aboveStr, mp, 0, "");
    }

    // get the current pair of blocks
    string pair = curr.substr(idx, 2);
    
    // check if no valid top block exists for this pair, fail early
    if(mp.find(pair) == mp.end()) return memo[key] = false;

    // try all possible blocks that can be placed on top of this pair (backtracking)
    for(char &ch : mp[pair]){
        // do
        aboveStr.push_back(ch);

        // backtrack -> explore
        if(solveRec(curr, mp, idx+1, aboveStr) == true){
            return memo[key] = true;
        }

        // undo
        aboveStr.pop_back();
    }

    // no valid configuration found
    return memo[key] = false;
}

bool pyramidTransition(string bottom, vector<string>& allowed) {
    // for mapping of bottom pair -> possible top blocks
    unordered_map<string, vector<char>> mp;

    // step 1 - build mapping from allowed patterns
    for(auto& pattern : allowed){
        mp[pattern.substr(0,2)].push_back(pattern[2]);
    }

    // step 2 - solve recursively and return
    return solveRec(bottom, mp, 0, "");
}

int main(){
    // string bottom = "BCD";
    // vector<string> allowed = {"BCC","CDE","CEA","FFF"};

    string bottom = "AAAA";
    vector<string> allowed = {"AAB","AAC","BCD","BBE","DEF"};
    bool res = pyramidTransition(bottom, allowed);
    res ? cout<<"true" : cout<<"false";
    return 0;
}
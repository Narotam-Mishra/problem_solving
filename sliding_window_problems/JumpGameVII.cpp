
// Problem link - https://leetcode.com/problems/jump-game-vii/description/?envType=daily-question&envId=2026-05-25

#include<bits/stdc++.h>
using namespace std;

int n;

// memoization array: memo[i] stores result for index i
// memoization array for recursive approach: memoRec[i] stores result for index i
vector<int> memoRec;

// recursive function to check if we can reach the end from index i
bool solveRec(int i, string& s, int minJump, int maxJump){
    // base case: if we reach the last index (n-1), we've successfully reached the end
    if(i == n-1) return true;

    // step 1 - check if this state has been computed before (memoization)
    if(memoRec[i] != -1) return memoRec[i];
    
    // step 2 - try all possible jumps from current position i
    for(int jump=minJump; jump<=maxJump; jump++){
        // calculate the landing position
        int j = i + jump;

        // step 3 - stop if landing position exceeds string length
        if(j >= n) break;

        // step 4 - only consider landing positions with '0' (no obstacle)
        if(s[j] == '0'){
            // step 5 - recursively check if we can reach end from position j
            if(solveRec(j, s, minJump, maxJump)){
                // step 6 - store result in memo and return true
                return memoRec[i] = true;
            }
        }
    }

    // step 7 - no valid jump found, store false in memo and return
    return memoRec[i] = false;
}

bool canReach1(string s, int minJump, int maxJump) {
    // get the length of the string
    n = s.length();

    // step 1 - initialize memoization array with -1 (not computed)
    // initialize recursive memoization array with -1 (unknown)
    memoRec.resize(n, -1);

    // step 2 - start the recursive search from index 0
    return solveRec(0, s, minJump, maxJump);
}

// optimal approach using sliding window
bool canReach(string s, int minJump, int maxJump) {
    // get the length of the string
    int n = s.length();

    // reachable[i] == 1 means index i is reachable from start under constraints
    vector<int> reachable(n, 0);

    // starting index is reachable if it's '0'
    reachable[0] = 1;

    // keep track of number of reachable positions in the sliding window
    int windowReachableCount = 0;

    // step 1 - iterate through each index
    for(int j = 1; j <= n - 1; j++){
        // step 2 - include new index that enters the window on the left: j - minJump
        if(j - minJump >= 0){
            windowReachableCount += reachable[j - minJump];
        }

        // step 3 - exclude index that leaves the window on the right: j - maxJump - 1
        if(j - maxJump - 1 >= 0){
            windowReachableCount -= reachable[j - maxJump - 1];
        }

        // step 4 - current position j is reachable if there's at least one reachable index
        if(windowReachableCount > 0 && s[j] == '0'){
            reachable[j] = 1;
        }
    }

    // step 5 - return true index (n-1) is reachable
    return reachable[n-1] > 0;
}

int main(){
    string s = "011010";
    int minJump = 2, maxJump = 3;

    // string s = "01101110";
    // int minJump = 2, maxJump = 3;
    bool res = canReach(s, minJump, maxJump);
    res ? cout<<"true" : cout<<"false";
    return 0;
}
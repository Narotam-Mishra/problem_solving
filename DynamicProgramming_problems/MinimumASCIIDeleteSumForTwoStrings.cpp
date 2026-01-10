
// Problem link - https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/?envType=daily-question&envId=2026-01-10

#include<bits/stdc++.h>
using namespace std;

int m, n;

// for memoization
int memo[1001][1001];

int solveRec(int i, int j, string& s1, string& s2){
    // base case: both strings are fully traversed
    if(i >= m && j >= n){
        return 0;
    }

    // if this state was already computed then return it
    if(memo[i][j] != -1){
        return memo[i][j];
    }

    // recursive case:
    // case 1 - s1 is exhausted -> delete all remaining characters from s2
    if(i >= m){
        return s2[j] + solveRec(i, j+1, s1, s2);
    }

    // case 2 - s2 is exhausted -> ddelete all remaining characters from s1
    if(j >= n){
        return s1[i] + solveRec(i+1, j, s1, s2);
    }

    // check if current characters are equal
    // no deletion need -> move forward
    if(s1[i] == s2[j]){
        return solveRec(i+1, j+1, s1, s2);
    }

    // option 1 - delete character from s1
    int delS1 = s1[i] + solveRec(i+1, j, s1, s2);

    // option 2 - delete character from s2
    int delS2 = s2[j] + solveRec(i, j+1, s1, s2);

    // memoize and return minimum cost
    return memo[i][j] = min(delS1, delS2);
}

int minimumDeleteSum(string s1, string s2) {
    // find size of string s1 & s2
    m = s1.size();
    n = s2.size();

    // reset
    memset(memo, -1, sizeof(memo));

    // step 1 - solve recursively and return
    return solveRec(0, 0, s1, s2);
}

int main(){
    // string s1 = "sea", s2 = "eat";

    string s1 = "delete", s2 = "leet";
    cout<<minimumDeleteSum(s1, s2);
    return 0;
}
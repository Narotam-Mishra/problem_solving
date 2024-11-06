
// Problem link : https://leetcode.com/problems/rotate-string/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    // cornor case: check if lengths are the same, 
    // if not, s can't be shifted to become goal
    if(s.size() != goal.size()) return false;

    // concatenate s with itself to cover all possible rotations
    string doubleStr = s + s;

    // check if goal is a substring of doubleS
    return doubleStr.find(goal) != string::npos;
}

int main(){
    // string s = "abcde", goal = "cdeab";

    string s = "abcde", goal = "abced";
    bool res = rotateString(s, goal);
    res ? cout<<"true" : cout<<"false";
    return 0;
}
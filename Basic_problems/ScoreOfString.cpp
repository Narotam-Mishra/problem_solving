
// Problem link - https://leetcode.com/problems/score-of-a-string/?envType=daily-question&envId=2024-06-01

#include<bits/stdc++.h>
using namespace std;

int scoreOfString(string s) {
    int absDiff = 0;
    for(int i=1; i<s.size(); i++){
        // calculate the absolute difference between adjacent characters
        absDiff += abs(s[i-1] - s[i]);
    }
    return absDiff;
}

int main(){
    string str = "hello";
    cout<<scoreOfString(str)<<endl;
    return 0;
}
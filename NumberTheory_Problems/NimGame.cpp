
// Problem link - https://leetcode.com/problems/nim-game/?envType=problem-list-v2&envId=brainteaser

#include<bits/stdc++.h>
using namespace std;

bool canWinNim(int n) {
    // you can win if and only if n is not dvisible by 4
    return n % 4 != 0;
}

int main(){
    // int n = 4;

    // int n = 1;

    int n = 2;
    bool res = canWinNim(n);
    res ? cout<<"true" : cout<<"false";
    return 0;
}
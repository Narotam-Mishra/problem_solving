
// Problem link : https://leetcode.com/problems/power-of-four/

#include<bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n) {
    bool exp1 = n > 0 && (n & (n-1)) == 0;
    bool exp2 = (n & 0xAAAAAAAA) == 0;
    return exp1 && exp2;
}

int main(){
    int num = 8;
    bool ans = isPowerOfFour(num);
    ans == 1 ? cout<<"true" : cout<<"false";
    return 0;
}
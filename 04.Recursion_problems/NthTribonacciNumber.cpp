
// Problem link - https://leetcode.com/problems/n-th-tribonacci-number/description/

#include<bits/stdc++.h>
using namespace std;

int tribonacci(int n) {
    if(n == 0) return 0;
    else if(n == 1 || n == 2) return 1;
    else{
        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
}

int main(){
    int num = 25;
    cout<<tribonacci(num)<<endl;
    return 0;
}
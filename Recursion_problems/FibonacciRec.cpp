
// Problem link - https://leetcode.com/problems/fibonacci-number/description/

// Approach - using Recursion

#include<bits/stdc++.h>
using namespace std;

int findFibonacciRec(int n){
    if(n == 0 || n == 1) return n;

    return findFibonacciRec(n-1) + findFibonacciRec(n-2);
}

int fib(int n) {
    return findFibonacciRec(n);
}
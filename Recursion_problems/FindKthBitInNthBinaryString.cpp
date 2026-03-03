
// Problem link - https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/?envType=daily-question&envId=2026-03-03

#include<bits/stdc++.h>
using namespace std;

char findKthBit(int n, int k) {
    // base case: S(1) = "0"
    if(n == 1) return '0';

    // step 1 - calculate the length of S(n)
    // S(n) has length 2^n - 1
    int len = (1 << n) - 1;
    
    // step 2 - calculate the middle position of S(n)
    int mid = (len + 1) / 2;

    // case 1: k is in the first half of S(n)
    // S(n) = S(n-1) + "1" + reverse_and_flip(S(n-1))
    // If k is before middle, recurse on S(n-1)
    if(k < mid){
        return findKthBit(n-1, k);
    }

    // case 2: k is at the middle position
    // The middle element is always '1'
    else if(k == mid){
        return '1';
    }

    // case 3: k is in the second half of S(n)
    // The second half is reverse_and_flip(S(n-1))
    // Map position k to corresponding position in S(n-1)
    else{
        // mirror the position: map k to its equivalent in S(n-1)
        // then reverse means we need to flip bits
        char ch = findKthBit(n-1, len - k + 1);
        
        // flip the bit: '0' becomes '1' and '1' becomes '0'
        return (ch == '0') ? '1' : '0';
    }
}

int main(){
    // int n = 3, k = 1;

    int n = 4, k = 11;
    cout<<findKthBit(n,k);
    return 0;
}
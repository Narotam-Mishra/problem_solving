
// Problem link : https://leetcode.com/problems/number-complement/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

int findComplement(int num) {
    // edge case
    if(num <= 0){
        return 1;
    }
    
    // step 1: find the bit length of the number
    int bitLength = log2(num) + 1;

    // step 2: create a mask of the same length with all bits set to 1
    unsigned int bitMask = (1U << bitLength) - 1;

    // step 3: XOR the number with the mask to get the complement
    return bitMask ^ num;
}

int main(){
    // int num = 5;

    int num = 1;
    cout<<findComplement(num);
    return 0;
}
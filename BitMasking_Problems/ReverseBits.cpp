
// Problem link : https://leetcode.com/problems/reverse-bits/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    // initialize the result to 0
    uint32_t res = 0;

    // loop through each of the 32 bits
    for(int i=0; i<32; i++){
        // shift result to the left by 1 bit to make room for the next bit
        // then extract the least significant bit of n and add it to result
        res = (res << 1) | (n & 1);
        
        // shift n to the right by 1 bit to process the next bit
        n >>= 1;
    }

    return res;
}

int main(){
    uint32_t num = 0b00000010100101000001111010011100;

    // uint32_t num = 0b111111111111111111111111111111010;
    cout<<reverseBits(num)<<endl;
    return 0;
}
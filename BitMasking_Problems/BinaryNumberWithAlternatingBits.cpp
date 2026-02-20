
// Problem link : https://leetcode.com/problems/binary-number-with-alternating-bits/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

bool hasAlternatingBits1(int n) {
    // XOR the number with its right-shifted version by 1 bit.
    // this helps to check if adjacent bits are different.
    unsigned int x = (n >> 1) ^ n;

    // check if the result of the XOR operation is a sequence of all 1s.
    // adding 1 to such a sequence would give a number with exactly one 1 bit followed by all 0s.
    // if x & (x + 1) results in 0, then the number had alternating bits.
    bool ans = (x & (x + 1)) == 0;
    return ans;
}

bool hasAlternatingBits(int n) {
    // using bitset container to store number in bits
    bitset<32> b(n);

    // step 1 - find highest set bit
    int highestSetBit = log2(n);

    // step 2 - iterate on each bit 
    for(int i=0; i<=highestSetBit; i++){
        // step 3 - check if it has consecutive bit or not
        if(b[i] == b[i+1]){
            // return false immediately
            return false;
        }
    }

    // step 4 - return true once all bit iteration completed
    return true;
}

int main(){
    // int num = 5;

    // int num = 9;

    // int num = 7;

    int num = 11;
    bool res = hasAlternatingBits(num);
    res == 1 ? cout<<"true" : cout<<"false";
    return 0;
}
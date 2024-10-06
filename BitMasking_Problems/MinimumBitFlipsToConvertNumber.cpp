
// Problem link : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
    // XOR the two numbers. The result will have bits set to 1 where x and y have different bits.
    int xorVal = start ^ goal;

    // initialize a counter to keep track of the number of different bits
    int dist = 0;

    // loop through all bits in the XOR result
    while(xorVal > 0){
        // increment the counter if the least significant bit is 1
        dist += xorVal & 1;

        // right shift the XOR result by 1 to check the next bit
        xorVal = xorVal >> 1;
    }

    // return the total count of different bits
    return dist;
}

int main(){
    int start = 10, goal = 7;
    cout<<minBitFlips(start, goal);
    return 0;
}
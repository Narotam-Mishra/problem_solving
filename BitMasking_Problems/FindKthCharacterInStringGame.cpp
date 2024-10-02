
// Problem link : https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

char kthCharacter(int k) {
    // get number of set bits in the binary representation of (k - 1)
    int flips = __builtin_popcount(k-1);
    
    // final character is determined by how many flips (bit counts) have occurred
    // we start with 'a' and move ahead in the alphabet by the number of flips
    return (char)('a' + flips);
}

int main(){
    // int k = 5;

    // int k = 100;

    int k = 500;
    cout<<kthCharacter(k);
    return 0;
}
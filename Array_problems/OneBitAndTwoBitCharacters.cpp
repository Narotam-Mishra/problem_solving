
// Problem link - https://leetcode.com/problems/1-bit-and-2-bit-characters/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

bool isOneBitCharacter(vector<int>& bits) {
    // step 1 - start from the beginning of the array `bits`
    int i = 0;

    // step 2 - process each bit unless we reach or pass the last position
    while (i < bits.size() - 1) {
        // step 3 - if current bit is `0` then it is 1-Bit Character
        if (bits[i] == 0) {
            // so move forward by 1-position
            i++;
            // step 4 - otherwise it is 2-Bit Character
        }
        else {
            // so move forward by 2-positions
            i += 2;
        }
    }

    // step 5 - if we landed on last bit position then it is 1-Bit Character, so return true
    // otherwise it is 2-Bits Character, so return false
    return i == bits.size() - 1;
}

int main(){
    // vector<int> bits = {1,0,0};

    vector<int> bits = {1,1,1,0};
    bool res = isOneBitCharacter(bits);
    res ? cout<<"true" : cout<<"false";
    return 0;
}
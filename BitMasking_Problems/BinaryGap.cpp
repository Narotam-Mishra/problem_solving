
// Problem link : https://leetcode.com/problems/binary-gap/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

int binaryGap1(int n) {
    // keep track of maximum distance
    int maxDistance = 0;

    // keep track of last and curr 1's position
    int lastPos = -1;
    int currPos = 0;

    // step 1 - iterate on each bit of `n`
    while (n > 0) {
        // step 2 - check if the current bit is 1
        if (n & 1) {
            if (lastPos != -1) {
                // step 3 - calculate the distance between the current and last 1
                maxDistance = max(maxDistance, currPos - lastPos);
            }
            // step 4 - update the position of the last 1
            lastPos = currPos;
        }
        // shift right to process the next bit
        n = n >> 1;

        // step 5 - update current position 'currPos'
        currPos++;
    }

    // step 6 - return maximum distance 'maxDistance'
    return maxDistance;
}

int binaryGap(int n) {
    // keep track of last 1's position
    int prevPos = -1;

    // keep track of maximum distance in `res`
    int res = 0;

    // step 1 - iterate of 32-bits
    for(int cp=0; cp<32; cp++){
        // step 2 - check if current bit is 1 or not (set bit)
        if(((n >> cp) & 1) > 0){
            // step 3 - update longest distance
            res = (prevPos != -1) ? max(res, cp - prevPos) : res;
            
            // update previous 1's position
            prevPos = cp;
        }
    }

    // step  4 - return longest distance
    return res;
}

int main(){
    int num = 22;

    // int num = 8;

    // int num = 5;
    cout<<binaryGap(num);
    return 0;
}
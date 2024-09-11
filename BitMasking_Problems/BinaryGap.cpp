
// Problem link : https://leetcode.com/problems/binary-gap/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

int binaryGap(int n) {
    int maxDistance = 0;
    int lastPos = -1;
    int currPos = 0;

    while(n > 0){
        // check if the current bit is 1
        if(n & 1){
            if(lastPos != -1){
                // calculate the distance between the current and last 1
                maxDistance = max(maxDistance, currPos - lastPos);
            }
            // update the position of the last 1
            lastPos = currPos;
        }
        // shift right to process the next bit
        n = n >> 1;
        // update current position 'currPos'
        currPos++;
    }
    // return maximum distance 'maxDistance'
    return maxDistance;
}

int main(){
    // int num = 22;

    // int num = 8;

    int num = 5;
    cout<<binaryGap(num);
    return 0;
}
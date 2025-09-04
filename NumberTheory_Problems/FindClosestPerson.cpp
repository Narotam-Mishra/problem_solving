
// Problem link - https://leetcode.com/problems/find-closest-person/?envType=daily-question&envId=2025-09-04

#include<bits/stdc++.h>
using namespace std;

int findClosest(int x, int y, int z) {
    // step 1 - find absolute difference (distance)
    // between `x` & `z` and `y` & `z`
    int distX = abs(z - x);
    int distY = abs(z - y);

    // step 2 - compare each speed and return
    if (distX < distY) {
        return 1;
    }
    else if (distY < distX) {
        return 2;
    }
    else {
        return 0;
    }
}

int main(){
    // int x = 2, y = 7, z = 4;

    // int x = 2, y = 5, z = 6;

    int x = 1, y = 5, z = 3;
    cout<<findClosest(x,y,z);
    return 0;
}

// Problem link - https://leetcode.com/problems/sqrtx/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int s = 1, e = x;

        while(s <= e){
            int mid = s + (e - s)/2;

            if(mid == x/mid){
                return mid;
            }else if(mid < x/mid){
                // discard left half of array
                s = mid + 1;
            }else{
                // discard right half of array
                e = mid - 1;
            }
        }
        return e;
    }
};

// Problem link - https://leetcode.com/problems/guess-number-higher-or-lower/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int guess(int num){

    }
    int guessNumber(int n) {
        int s = 1, e = n;

        while(s <= e){
            int mid = s + (e-s)/2;
            int res = guess(mid);
            if(res == 0) return mid;
            else if(res == 1){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return s;
    }
};
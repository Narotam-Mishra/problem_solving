
// Problem link - https://leetcode.com/problems/arranging-coins/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long s = 1, e = n;
        long ans = 1;

        while(s <= e){
            long mid = s + (e - s)/2;
            long val = (mid * (mid+1))/2;
            if(val <= n){
                // get first potential ans, 
                ans = mid;
                // as we have find maximum number of rows (i.e mid), hence we discard left half of array
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return (int) ans;
    }
};
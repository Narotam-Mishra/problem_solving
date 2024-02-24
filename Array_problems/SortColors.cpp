
// Problem link - https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cz = 0, co = 0, ct = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) cz++;
            else if(nums[i] == 1) co++;
            else ct++;
        }

        int k = 0;
        while(cz > 0){
            nums[k++] = 0;
            cz--;
        }

        while(co > 0){
            nums[k++] = 1;
            co--;
        }

        while(ct > 0){
            nums[k++] = 2;
            ct--;
        }
    }
};
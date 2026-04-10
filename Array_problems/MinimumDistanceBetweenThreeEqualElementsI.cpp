
// Problem link - https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description/?envType=daily-question&envId=2026-04-10

#include<bits/stdc++.h>
using namespace std;

int minimumDistance(vector<int>& nums) {
    int minDistance = INT_MAX;

    // step 1 - try every combination of 3 distinct indices
    int n = nums.size();
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                // step 2 - check if it form a good tuple
                if(nums[i] == nums[j] && nums[j] == nums[k]){
                    // step 3 - compute distance 
                    int dist = abs(i-j) + abs(j-k) + abs(k-i);

                    // step 4 - update minimum distance
                    minDistance = min(minDistance, dist);
                }
            }
        }
    }

    // step 5 - return final minimum distance
    return minDistance == INT_MAX ? -1 : minDistance;
}

int main(){
    // vector<int> nums = {1,2,1,1,3};

    // vector<int> nums = {1,1,2,3,2,1,2};

    vector<int> nums = {1};
    cout<<minimumDistance(nums);
    return 0;
}
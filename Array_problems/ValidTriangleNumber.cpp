
// Problem link - https://leetcode.com/problems/valid-triangle-number/?envType=daily-question&envId=2025-09-26

#include<bits/stdc++.h>
using namespace std;

int triangleNumber(vector<int>& nums) {
    // store the count of valid triangle's triplets
        int count = 0;
        int n = nums.size();

        // step 1 - sort the array
        sort(nums.begin(), nums.end());

        // step 2 - fix the largest side and find pairs for the other two sides
        // we iterate from the end because after sorting, the largest element
        // will be at the end, and we want to fix it as the longest side
        for(int i=n-1; i>=2; i--){
            // step 3 - using two pointers
            // left pointer, `s` starts from beginning, right, `e` from i-1
            int s = 0, e = i-1;

            // Triangle inequality: For three sides a, b, c (where c is largest)
            // a + b > c is the only condition we need to check
            // (since a + c > b and b + c > a are automatically satisfied when c is largest)
            while(s < e){
                // step 4 - check if current triplet forms a valid triangle
                if(nums[s] + nums[e] > nums[i]){
                    // if nums[s] + nums[e] > nums[k], then all pairs
                    // (s, s+1), (s, s+2), ..., (s, e)
                    // will also satisfy the condition with nums[i] as nums is sorted
                    count += (e - s);
                    e--;
                }else{
                    // if sum is not greater than nums[i], we need a larger sum
                    // so move left pointer rightward to get larger values
                    s++;
                }
            }
        }

        // step 5 - return final count
        return count;
}

int main(){
    // vector<int> nums = {2,2,3,4};

    vector<int> nums = {4,2,3,4};
    cout<<triangleNumber(nums);
    return 0;
}


// Problem link - https://leetcode.com/problems/range-sum-query-immutable/description/

#include<bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i=left; i<=right; i++){
            sum += nums[i];
        }
        return sum;
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    NumArray numArray(nums);

    // Test the sumRange method
    cout<<numArray.sumRange(0, 2)<<endl; // Output: 6 (1 + 2 + 3)
    cout<<numArray.sumRange(1, 3)<<endl; // Output: 9 (2 + 3 + 4)
    cout<<numArray.sumRange(2, 4)<<endl; // Output: 12 (3 + 4 + 5)
    return 0;
}
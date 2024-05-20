
// Problem link - https://leetcode.com/problems/sliding-window-maximum/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if(nums.empty() || k <= 0) return {};
    vector<int> res;
    deque<int> dq;

    // prepare window for n elements
    for(int i=0; i<nums.size(); i++){
        // remove elements from the deque that are smaller than the current element
        while (!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }

        // remove indices outside the window k
        while(!dq.empty() && dq.front() < i-k+1){
            dq.pop_front();
        }

        // Add the current index to the deque
        dq.push_back(i);

        // add required maximum window element fromt deque into result array res
        if(i >= k-1){
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    for(int num : ans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
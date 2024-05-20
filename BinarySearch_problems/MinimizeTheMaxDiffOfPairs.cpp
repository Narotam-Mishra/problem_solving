
//Problem link - https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

#include<bits/stdc++.h>
using namespace std;

bool canFormAtleastPpairsWithAtmostMidDifference(vector<int>& arr, int mid, int p){
    int i=0, count = 0;
    while(i < arr.size() - 1){
        // check whether the diff is atmost mid
        if(arr[i+1] - arr[i] <= mid){
            count++;
            i += 2;
        }else{
            i++;
        }
    }
    return count >= p;
}
int minimizeMax(vector<int>& nums, int p) {
    // sort the array to easily find p pairs
    sort(nums.begin(), nums.end());

    // for search space minimum value, low is 0 and maximum value, high is maximum - minimum value in nums array
    int low = 0, high = nums[nums.size() - 1] - nums[0];
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(canFormAtleastPpairsWithAtmostMidDifference(nums, mid, p)){
            // found first probable ans as mid
            ans = mid;
            // since difference amongst all the pairs is minimized
            // hence we will discard right half of search space
            high = mid - 1;
        }else{
            // otherwise discard left half of search space
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {10,1,2,7,1,3};
    int p = 2;
    int ans = minimizeMax(arr, p);
    cout<<ans<<endl;
    return 0;
}
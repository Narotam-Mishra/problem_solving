
#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    // sort array numbers
    sort(nums.begin(), nums.end());

    for(int i=1; i<nums.size(); i++){
        if(nums[i] == nums[i-1]){
            return nums[i];
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1, 3, 4, 2, 2};
    cout << findDuplicate(arr) << endl;
    return 0;
}
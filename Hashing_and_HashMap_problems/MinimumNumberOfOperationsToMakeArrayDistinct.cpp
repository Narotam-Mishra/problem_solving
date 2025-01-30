
#include<bits/stdc++.h>
using namespace std;

int minimumOperations(vector<int>& nums) {
    // step 1 - create boolean array map to track seen numbers
    vector<bool> freqMap(101, false);

    // step 1 - create boolean array map to track seen numbers
    for(int i=nums.size()-1; i>=0; i--) {
        if(freqMap[nums[i]]){
                // step 3: compute the minimum number of operations required
                return (int)(i+3)/3;
            }
        // mark the number in frquency array map
        freqMap[nums[i]] = true;
    }
    return 0;
}

int main(){
    vector<int> nums = {1,2,3,4,2,3,3,5,7};
    cout<<minimumOperations(nums)<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxOnes = 0, counter = 0;

    // iterate each numbers
    for(int i=0; i<nums.size(); i++){
        // count ones
        if(nums[i] == 1){
            counter++;
            // find maximum ones
            maxOnes = max(counter, maxOnes);
        }else{
            counter = 0;
        }
    }
    // return maxOnes
    return maxOnes;
}

int main(){
    vector<int> arr = {1,1,0,1,1,1};
    cout<<findMaxConsecutiveOnes(arr);
}
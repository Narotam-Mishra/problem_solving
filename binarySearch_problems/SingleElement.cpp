
#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int s = 0, e = nums.size() - 1;

    while(s < e){
        int mid = (s + e)/2;

        if(mid % 2 == 1){
            mid--;
        }

        // if pair is intact (i.e mid and mid+1 th elements are same)
        // discard left half of array
        if(nums[mid] == nums[mid+1]){
            s = mid + 2;
        }else{
            // othewise discard right half of array
            e = mid - 1;
        }
    }
    return nums[s];
}

int main(){
    vector<int> arr = {1,1,2,3,3,4,4,8,8};
    int ans = singleNonDuplicate(arr);
    cout<<ans<<endl;
    return 0;
}
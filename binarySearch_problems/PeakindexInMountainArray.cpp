
// Problem link - https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

#include<bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int low = 0, high = arr.size()-1;
    while(low < high){
        int mid = low + (high - low)/2;
        if(arr[mid] < arr[mid+1]){
            // dicard left half of array
            low = mid + 1;
        }else{
            // got first proabable peak element index
            high = mid;
        }
    }
    return high;
}

int main(){
    vector<int> arr = {0,10,5,2};
    int ans = peakIndexInMountainArray(arr);
    cout<<ans<<endl;
    return 0;
}
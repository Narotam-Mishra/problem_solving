
// Problem link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include<bits/stdc++.h>
using namespace std;

bool canShipMidWeightsWithinDdays(vector<int>& arr, int mid, int days){
    int dc = 0, rw = 0;
    for(int i=0; i<arr.size(); i++){
        if(rw + arr[i] > mid){
            dc++;
            rw = 0;
        }
        rw += arr[i];
    }
    // increment day counter, dc for last running weight sum, rw
    dc++; 
    return dc<=days;
}
int shipWithinDays(vector<int>& weights, int days) {
    int maxWeight = -1, totalWeight = 0;

    for(int w: weights){
        maxWeight = max(maxWeight, w);
        totalWeight += w;
    }

    // since we may not load more weight than the maximum weight capacity of the ship.
    //hence search space will be from low = maxweight to high = totalWeight
    int low = maxWeight, high = totalWeight;
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(canShipMidWeightsWithinDdays(weights, mid, days)){
            // found the first probable answer, ans
            ans = mid;
            // since we have to find least weight capacity,
            // we will discard right half of search space
            high = mid - 1;
        }else{
            // otherwise discard left half of search space
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    int ans = shipWithinDays(arr, days);
    cout<<ans<<endl;
    return 0;
}

// Problem link - https://leetcode.com/problems/koko-eating-bananas/description/

#include<bits/stdc++.h>
using namespace std;

bool canKokoEatAllBananasInMidSpeed(vector<int>& piles, int mid, int h){
    // time taken to eat a pile of banans = ceil value of(piles[i]/mid)
    // where piles[i] is number of bananas in ith pile and 'mid' is speed
    long totalHrsToEat = 0;
    for (int i = 0; i < piles.size(); i++) {
        // total time to finish ith pile of bananas
        // Cast one operand to double to perform decimal division
        totalHrsToEat += ceil(static_cast<double>(piles[i]) / mid);
    }
    // check if total bananas finished within h hours
    return totalHrsToEat <= h;
}

int minEatingSpeed(vector<int> &piles, int h){
    // define the search space to determine minimum speed k
    // minimum 1 and maximum max number of piles to determine search space
    int maxBananas = INT_MIN;
    for (int num : piles){
        maxBananas = max(maxBananas, num);
    }
    // let us assume ans i.e minimum speed is 1
    int s = 1, e = maxBananas, ans = 1;

    while (s <= e){
        long mid = (s + e) / 2;
        // check if Koko can eat all bananas at mid speed within 'h' hrs
        if (canKokoEatAllBananasInMidSpeed(piles, mid, h)){
            // get one probable ans as mid
            ans = mid;
            // since we need to find minimum speed 'k' hence we discard right half of array
            e = mid - 1;
        }
        else{
            // otherwise discard left half of array
            s = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {30,11,23,4,20};
    int h = 5;
    int ans = minEatingSpeed(arr,h);
    cout<<ans<<endl;
    return 0;
}
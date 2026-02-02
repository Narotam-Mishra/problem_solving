
// Problem link - https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/?envType=daily-question&envId=2026-02-02

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll minimumCost(vector<int>& nums, int k, int dist) {
    int n = nums.size();

    // stores (k-1) minimum elements
    set<P> kMin;
    set<P> rem;

    // keep track of (k-1) minimum elements
    ll sum = 0;

    // step 1 - using sliding window technique
    int i = 1;
    while(i - dist < 1){
        kMin.insert({nums[i], i});
        sum += nums[i];

        // step 2 - window have exactly k-1 elements
        if(kMin.size() > k-1){
            P temp = *kMin.rbegin();
            sum -= temp.first;
            rem.insert(temp);
            kMin.erase(temp);
        }

        // step 3 - move to next element
        i++;
    }

    ll res = LONG_MAX;
    while(i < n){
        kMin.insert({nums[i], i});
        sum += nums[i];

        if(kMin.size() > k-1){
            P temp = *kMin.rbegin();
            sum -= temp.first;
            rem.insert(temp);
            kMin.erase(temp);
        }

        res = min(res, sum);

        // step 4 - shift window and remove (i-dist)th element
        P remove = {nums[i-dist], i-dist};
        if(kMin.count(remove)){
            kMin.erase(remove);
            sum -= remove.first;

            if(!rem.empty()){
                P temp = *rem.begin();
                kMin.insert(temp);
                sum += temp.first;
                rem.erase(temp);
            }
        }else{
            rem.erase(remove);
        }
        i++;
    }

    // step 6 - return final result
    return nums[0] + res;
}

int main(){
    // vector<int> nums = {1,3,2,6,4,2};
    // int k = 3, dist = 3;

    // vector<int> nums = {10,1,2,2,2,1};
    // int k = 4, dist = 3;

    vector<int> nums = {10,8,18,9};
    int k = 3, dist = 1;
    cout<<minimumCost(nums, k, dist);
    return 0;
}
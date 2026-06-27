
// Problem link - https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/description/?envType=daily-question&envId=2026-06-27

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int maximumLength(vector<int>& nums) {
    // step 1 - build frequency map for each number in nums
    unordered_map<ll, int> frq;
    for(int num : nums){
        frq[(ll)num]++;
    }

    // keep track of final answer in `ans`
    int ans = 1;

    // step 2 - handle edge case when x=1
    // all powers of 1 are 1, so we can use any odd number of 1s
    if(frq.count(1)){
        int c = frq[1];
        int currAns = (c % 2 == 1) ? c : c-1;
        ans = max(ans, currAns);
    }

    // define maximum limit for power value
    const ll limit = 1000000000LL;

    // step 3 - process every distinct value x > 1 as a potential base
    for(auto &p : frq){
        ll x = p.first;
        // handled x==1 separately
        if(x == 1) continue;

        // step 4 - build the chain x, x^2, x^4, ...
        vector<pair<ll, int>> chain;
        ll val = x;

        while(val <= limit && frq.count(val)){
            chain.push_back({val, frq[val]});
            ll nextVal = val * val;
            if(nextVal > limit) break;
            val = nextVal;
        }

        // step 5 - find the first index where frequency < 2
        int firstBadFrq = (int)chain.size();
        for(int i=0; i<(int)chain.size(); i++){
            if(chain[i].second < 2){
                firstBadFrq = i;
                break;
            }
        }

        // step 6 - the best `m` is limited by firstBadFrq and the chain length
        int m = min(firstBadFrq, (int)chain.size()-1);
        int size = 2*m + 1;

        // step 7 - update answer with 2*m + 1
        ans = max(ans, size);
    }

    return ans;
}

int main(){
    // vector<int> nums = {5,4,1,2,2};

    // vector<int> nums = {1,3,2,4};

    vector<int> nums = {1,16,49,16,121};
    cout<<maximumLength(nums);
    return 0;
}
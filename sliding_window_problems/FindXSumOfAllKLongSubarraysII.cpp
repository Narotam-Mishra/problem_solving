
// Problem link - https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/description/?envType=daily-question&envId=2025-11-05

#include<bits/stdc++.h>
using namespace std;

vector<long long> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();

    // store final result in res
    vector<long long> res;

    // maintains sum of top x elements from main set
    long long sum = 0;

    // main set contains top x {frequency, element}
    set<pair<int, int>> ms;

    // secondary set, sec contains remaining {frequency, element}
    set<pair<int, int>> sec;

    // track frequency of each element in current window
    unordered_map<int, int> mp;

    // helper lambda function to insert a {frequency, value} pair into appropriate set
    auto insertInSetInPair = [&](const pair<int, int>& p, int x) {
        // if main set(ms) has room OR this element is larger than smallest in main set(ms)
        if (ms.size() < x || p > *ms.begin()) {
            // add to main set and update running sum
            sum += 1LL * p.first * p.second;
            ms.insert(p);

            // if main set(ms) exceeds size x, move smallest to secondarySet
            if (ms.size() > x) {
                auto smallest = *ms.begin();
                sum -= 1LL * smallest.first * smallest.second;
                ms.erase(smallest);
                sec.insert(smallest);
            }
        }
        else {
            // element doesn't qualify for top x, add to secondarySet
            sec.insert(p);
        }
    };
    
    // helper lambda function to remove a {frequency, value} pair from sets
    auto removeFromSetInPair = [&](const pair<int, int>& p) {
        // check if pair exists in mainSet
        if (ms.find(p) != ms.end()) {
            // remove from main set(ms) and update running sum
            sum -= 1LL * p.first * p.second;
            ms.erase(p);

            // move largest element from secondarySet to main set (ms) to fill the gap
            if (!sec.empty()) {
                auto largest = *sec.rbegin();
                sec.erase(largest);
                ms.insert(largest);
                sum += 1LL * largest.first * largest.second;
            }
        }
        else {
            // pair is in secondarySet, simply remove it
            sec.erase(p);
        }
    };

    // using sliding window approach
    int i = 0, j = 0;
    while (j < n) {
        // step 1 - remove old frequency pair if element already exists
        if (mp[nums[j]] > 0) {
            removeFromSetInPair({ mp[nums[j]], nums[j] });
        }

        // step 2 - increment frequency and insert new pair
        mp[nums[j]]++;
        insertInSetInPair({ mp[nums[j]], nums[j] }, x);

        // step 3 - when window reaches size k, record result and slide
        if (j - i + 1 == k) {
            res.push_back(sum);

            // remove leftmost element along with its frequency from window
            removeFromSetInPair({ mp[nums[i]], nums[i] });
            mp[nums[i]]--;

            // if frequency becomes 0, remove from map
            if (mp[nums[i]] == 0) {
                mp.erase(nums[i]);
            }
            else {
                // otherwise re-insert
                insertInSetInPair({ mp[nums[i]], nums[i] }, x);
            }
            i++;
        }
        j++;
    }

    // step 4 - return final result, res
    return res;
}

void printVector(vector<long long>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    // vector<int> nums = {1,1,2,2,3,4,2,3};
    // int k = 6, x = 2;

    vector<int> nums = {3,8,7,8,7,5};
    int k = 2, x = 2;
    vector<long long> res = findXSum(nums, k, x);
    printVector(res);
    return 0;
}
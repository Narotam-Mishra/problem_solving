
#include<bits/stdc++.h>
using namespace std;

int arithmeticTriplets(vector<int>& nums, int diff) {
    // step 1 - store nums array in set for quick lookup
    unordered_set<int> seen;
    int count = 0;
    for (int num : nums) {
        seen.insert(num);
    }

    // step 2 - iterate through nums and check for arithmetic triplets
    for (int num : nums) {
        if (seen.find(num + diff) != seen.end() && seen.find(num + (2 * diff)) != seen.end()) {
            // found valid triplet, increment count
            count++;
        }
    }

    // step 3 - return required count
    return count;
}

int main(){
    // vector<int> nums = {0,1,4,6,7,10};
    // int diff = 3;

    vector<int> nums = {4,5,6,7,8,9};
    int diff = 2;
    cout<<arithmeticTriplets(nums, diff)<<endl;
    return 0;
}
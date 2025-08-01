
// Problem link - https://leetcode.com/problems/check-if-any-element-has-prime-frequency/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

// utility function to check if number is prime or not
bool isPrimeNumber(int n) {
    if (n <= 1) return false;

    for (int i = 2; i <= int(sqrt(n)); i++) {
        if (n % i == 0) return false;
    }

    return true;
}

bool checkPrimeFrequency(vector<int>& nums) {
    // step 1 - create frequency array to store frquency of `nums` elements
    vector<int> frqArr(101, 0);

    // step 2 - count frequency of each `nums` element
    for (int num : nums) {
        frqArr[num]++;
    }

    // step 3 - iterate on frequency array
    for (int num : frqArr) {
        // step 4 - check if any frquency has prime frequency
        if (isPrimeNumber(num)) {
            return true;
        }
    }

    // step 5 - if none of the frequency is prime then return false
    return false;
}

int main(){
    // vector<int> nums = {1,2,3,4,5,4};

    // vector<int> nums = {1,2,3,4,5};

    vector<int> nums = {2,2,2,4,4};
    bool res = checkPrimeFrequency(nums);
    res ? cout<<"true" : cout<<"false";
}
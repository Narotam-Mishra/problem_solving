
// Problem link : https://leetcode.com/problems/sum-of-all-odd-length-subarrays/description/

#include<bits/stdc++.h>
using namespace std;

int sumOddLengthSubarrays(vector<int>& arr) {
    int totalSum = 0;
    int n = arr.size();

    // iterate on each array's element
    for (int i = 0; i < n; i++) {
        // the total number of subarrays that include arr[i]
        int subarrayCount = (i + 1) * (n - i);

        // the number of odd-length subarrays that include arr[i]
        int oddLengthSubarraysCount = (subarrayCount + 1) / 2;

        // add to the total sum the contribution of arr[i]
        totalSum += (arr[i] * oddLengthSubarraysCount);
    }
    // return total sum
    return totalSum;
}

int main(){
    vector<int> arr = {1, 4, 2, 5, 3};
    cout<<sumOddLengthSubarrays(arr)<<endl;
    return 0;
}
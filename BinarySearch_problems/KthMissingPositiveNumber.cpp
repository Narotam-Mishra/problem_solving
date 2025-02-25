
#include<bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    // define the search space
    int s = 0, e = arr.size() - 1;

    // step 1 - use binary search logic
    while (s <= e) {
        // calculate mid
        int mid = (s + e) / 2;

        // calculate the number of missing number counts
        int missingCounts = arr[mid] - (mid + 1);

        // if the missing numbers are less than k, move to the right
        if (missingCounts < k) {
            s = mid + 1;
        }
        // if the missing numbers are greater than or equal to k, move to the left
        else {
            e = mid - 1;
        }
    }

    // return kth missing number
    return k + e + 1;
}

int main(){
    // vector<int> arr = {2, 3, 4, 7, 11};
    // int k = 5;

    vector<int> arr = {1, 2, 3, 4};
    int k = 2;
    cout<<findKthPositive(arr, k)<<endl;
    return 0;
}
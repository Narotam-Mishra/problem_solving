
// Problem link - https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

#include<bits/stdc++.h>
using namespace std;

int findLowerBound(vector<int>& arr, long long x){
    int l = 0, r = arr.size() - 1;
    int ans = arr.size();

    while(l <= r){
        int mid = l + (r - l)/2;
        if(x > arr[mid]){
            // discard left half of array
            l = mid + 1;
        }else{
            // first proabable answer(ans) found
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    // sort potions array in ascending order
    sort(potions.begin(), potions.end());

    int n = spells.size();
    // array to count successful pairs
    vector<int> successPairs(n);

    for(int i=0; i<n; i++){
        // minimum stength required for success
        long long minStrength = ceil((double) success / spells[i]);
        // Count successful pairs
        int countPairs = potions.size() - findLowerBound(potions, minStrength);
        successPairs[i] = countPairs;
    }
    return successPairs;
}

int main(){
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1,2,3,4,5};
    int success = 7;
    vector<int> resArr = successfulPairs(spells, potions, success);

    for(int num : resArr){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
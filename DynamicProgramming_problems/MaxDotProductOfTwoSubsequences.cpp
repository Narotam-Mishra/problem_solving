
// Problem link - https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/?envType=daily-question&envId=2026-01-08

#include<bits/stdc++.h>
using namespace std;

int m, n;

// for memoization
int memo[501][501];

int solveRec(int i, int j, vector<int>& nums1, vector<int>& nums2){
    // base case
    if(i == m || j == n){
        return -1e9;
    }

    // if result is already computed then return it
    if(memo[i][j] != -1e9){
        return memo[i][j];
    }

    // recursive case: 4 possible cases
    int val = nums1[i] * nums2[j];
    int takeij = (nums1[i] * nums2[j]) + solveRec(i+1, j+1, nums1, nums2);
    int takei = solveRec(i, j+1, nums1, nums2);
    int takej = solveRec(i+1, j, nums1, nums2);

    // return maximum from all subsequences
    return memo[i][j] = max({val, takeij, takei, takej});
}

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    // find nums1 & nums2 size
    m = nums1.size();
    n = nums2.size();

    // initialize memo
    for(int i=0; i<501; i++){
        for(int j=0; j<501; j++){
            memo[i][j] = -1e9;
        }
    } 

    // step 1 - solve recursilvely and return result
    return solveRec(0,0,nums1,nums2);
}

int main(){
    vector<int> nums1 = {2,1,-2,5}, nums2 = {3,0,-6};

    // vector<int> nums1 = {3,-2}, nums2 = {2,-6,7};

    // vector<int> nums1 = {-1,-1}, nums2 = {1,1};
    cout<<maxDotProduct(nums1, nums2);
    return 0;
}
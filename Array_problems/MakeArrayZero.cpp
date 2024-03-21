
// Problem link - https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/

#include<bits/stdc++.h>
using namespace std;

int minimumOperations(vector<int>& nums) {
    int table[101] = {0};

    // add frequency of each non-zero numbers in frequency table
    for(int num : nums){
        table[num] += 1;
    } 

    int ans = 0;
    for(int i=1; i<101; i++){
        if(table[i] > 0){
            ans += 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,5,0,3,5};
    int ans = minimumOperations(arr);
    cout<<ans<<endl;
    return 0;
}
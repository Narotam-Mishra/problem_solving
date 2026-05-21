
// Problem link - https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2026-05-21

#include<bits/stdc++.h>
using namespace std;

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    // step 1 - build a set of all prefixes (as integers) that appear in arr1.
    unordered_set<int> st;
    for(int val : arr1){
        // insert val and all its numeric prefixes until 0 or prefix already seen.
        while(!st.count(val) && val > 0){
            st.insert(val);

            // drop the last digit to get the next shorter prefix
            val = val/10; 
        }
    }

    // keep track of longest prefix seen so far
    int longestPrefix = 0;

    // step 2 - now check numbers in arr2: reduce each number to its longest prefix
    for(int num : arr2){
        // reduce num until its current value is found in st or becomes 0.
        while (!st.count(num) && num > 0){
            // drop last digit
            num = num/10; 
        }

        // step 3 - check If we found a matching prefix (num > 0), compute its length in digits
        if(num > 0){
            longestPrefix = max(longestPrefix, (int)log10(num)+1);
        }
    }

    // step 4 - return the maximum common prefix length found
    return longestPrefix; 
}

int main(){
    // vector<int> arr1 = {1,10,100}, arr2 = {1000};

    vector<int> arr1 = {1,2,3}, arr2 = {4,4,4};
    cout<<longestCommonPrefix(arr1, arr2);
    return 0;
}
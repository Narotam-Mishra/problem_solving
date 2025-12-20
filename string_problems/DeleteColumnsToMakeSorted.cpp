
// Problem link - https://leetcode.com/problems/delete-columns-to-make-sorted/?envType=daily-question&envId=2025-12-20

#include<bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string>& strs) {
    // find size of array of strings
    int n = strs.size();

    // find size of each string
    int k = strs[0].length();

    // step 1 - iterate on each letter of string array
    int cnt = 0;
    for(int i=0; i<k; i++){
        for(int j=1; j<n; j++){
            // step 2 - check if current letter is less than previous letter of word
            if(strs[j][i] < strs[j-1][i]){
                // increment count and break
                cnt++;
                break;
            }
        }
    }

    // step 3 - return number of columns that you will delete
    return cnt;
}

int main(){
    // vector<string> strs = {"cba", "daf", "ghi"};

    // vector<string> strs = {"a", "b"};

    vector<string> strs = {"zyx", "wvu", "tsr"};
    cout<<minDeletionSize(strs);
    return 0;
}
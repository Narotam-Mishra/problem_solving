
// Problem link : https://leetcode.com/problems/find-lucky-integer-in-an-array/description/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

// utlity function to check if number is lucky or not
bool isLuckyNumber(int num, int count){
    return num == count;
}

int findLucky(vector<int>& arr) {
    // step 1 - create frequency map array to store frquency of each number from array
    vector<int> freqArr(501, 0);
    for (int num : arr) {
        freqArr[num]++;
    }

    // step 2 - iterate frquency array return largest Lucky number
    for (int i = freqArr.size() - 1; i > 0; i--) {
        if (isLuckyNumber(i, freqArr[i])) {
            return freqArr[i];
        }
    }

    // step 3 - otherwise return -1
    return -1;
}

int main(){
    // vector<int> arr = {2,2,3,4};

    // vector<int> arr = {1,2,2,3,3,3};

    vector<int> arr = {2,2,2,3,3};
    cout<<findLucky(arr)<<endl;
    return 0;
}
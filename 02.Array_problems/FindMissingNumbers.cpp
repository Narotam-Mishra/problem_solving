
#include<bits/stdc++.h>
using namespace std;

int findMinimum(vector<int>& arr) {
    int minNum = 99999999;
    for (int i = 0; i < arr.size(); i++) {
        minNum = min(minNum, arr[i]);
    }
    return minNum;
}

int findMaximum(vector<int>& arr) {
    int maxNum = -1;
    for (int i = 0; i < arr.size(); i++) {
        maxNum = max(maxNum, arr[i]);
    }
    return maxNum;
}

vector<int> findMissingNumbers(vector<int>& arr){
    // find maximum and minimum number in the list
    int minNum = findMinimum(arr);
    int maxNum = findMaximum(arr);

    // Create an unordered_set to mark presence of numbers
    unordered_set<int> presentNums;

    // mark numbers from the input array as present
    for(int num : arr){
        presentNums.insert(num);
    }

    // array of missNums to store missing numbers
    vector<int> missNums;
    for(int n=minNum; n <= maxNum; n++){
        if(presentNums.find(n) == presentNums.end()){
            missNums.push_back(n);
        }
    }

    return missNums;
}

int main(){
    vector<int> nums = {2,5,7};
    vector<int> ans = findMissingNumbers(nums);
    for(int num : ans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
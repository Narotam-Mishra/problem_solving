
#include<bits/stdc++.h>
using namespace std;

vector<int> frequencySort(vector<int>& nums) {
    // step 1 - count the frequency of each element
    unordered_map<int, int> frqMap;
    for(int num : nums){
        frqMap[num]++;
    }

    // step 2 - sort the array with a custom comparator
    // case 1 - first sort by frequency (ascending)
    // case 2 - if frequencies are the same, sort by value (descending)
    sort(nums.begin(), nums.end(), [&](int a, int b){
        // step 2.1 - if frequencies are equal, sort by value (descending)
        if(frqMap[a] == frqMap[b]){
            return a > b;
        }
        // step 2.2 - otherwise, sort by frequency (ascending)
        return frqMap[a] < frqMap[b];
    });

    // step 3 - return the sorted array
    return nums;
}

void printVector(vector<int>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    // vector<int> nums = {1,1,2,2,2,3};

    vector<int> nums = {2,3,1,3,2};
    vector<int> res = frequencySort(nums);
    printVector(res);
    return 0;
}
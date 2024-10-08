
// Problem link : https://leetcode.com/problems/two-out-of-three/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

// function to update frequency map based on unique elements from the input arra
void updateFrequency(unordered_map<int, int>& freqMap, vector<int>& arr){
    unordered_set<int> unique(arr.begin(), arr.end());
    for(int num : unique){
        freqMap[num]++;
    }
}
vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    // define a frequency map
    unordered_map<int, int> freqMap;

    // update frequency map for each array
    updateFrequency(freqMap, nums1);
    updateFrequency(freqMap, nums2);
    updateFrequency(freqMap, nums3);

    // collect numbers that appear in at least two arrays
    vector<int> res;
    for(auto& entry : freqMap){
        if(entry.second >= 2){
            res.push_back(entry.first);
        }
    }
    return res;
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
    vector<int> nums1 = {1, 1, 3, 2}, nums2 = {2, 3}, nums3 = {3};
    vector<int> res = twoOutOfThree(nums1, nums2, nums3);
    printVector(res);
    return 0;
}
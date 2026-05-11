
// Problem link - https://leetcode.com/problems/separate-the-digits-in-an-array/description/?envType=daily-question&envId=2026-05-11

#include<bits/stdc++.h>
using namespace std;

vector<int> separateDigits(vector<int>& nums) {
    // keep track of final result in `res`
    vector<int> res;

    // step 1 - iterate on each number of nums
    for (int num : nums) {
        // step 2 - convert each num to string
        string str = to_string(num);

        // step 3 - extract each digit from num
        for (char ch : str) {
            // store in `res`
            res.push_back(ch - '0');
        }
    }

    // step 4 - return final result, `res`
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
    // vector<int> nums = {13,25,83,77};

    vector<int> nums = {7,1,3,9};
    vector<int> res = separateDigits(nums);
    printVector(res);
    return 0;
}
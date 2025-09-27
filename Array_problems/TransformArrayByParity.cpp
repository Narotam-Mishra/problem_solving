
#include<bits/stdc++.h>
using namespace std;

vector<int> transformArray(vector<int>& nums) {
    // step 1 - iterate on array
    for (int i = 0; i < nums.size(); i++) {
        // step 2 - modify array's elements as per even-odd parity
        if (nums[i] % 2 == 0) {
            // for even-number update it to 0
            nums[i] = 0;
        }
        else {
            // for odd-number update it to 1
            nums[i] = 1;
        }
    }

    // step 3 - sort the array in non-decreasing order
    sort(nums.begin(), nums.end());

    // step 4 - return the final modified array as result
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
    // vector<int> nums = {4,3,2,1};

    vector<int> nums = {1,5,1,4,2};
    vector<int> res = transformArray(nums);
    printVector(res);
    return 0;
}
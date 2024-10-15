
// Problem link : https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

vector<int> minBitwiseArray(vector<int>& nums) {
    vector<int> res(nums.size(), 0);
    int id = 0;
    // iterate through each number in the nums array
    for (int num : nums) {
        bool found = false;

        // try values for ans[i] starting from 0 and upwards
        for (int i = 0; i <= num; i++) {

            // check if the condition holds: ans[i] OR (ans[i] + 1) == num
            if ((i | (i + 1)) == num) {
                // if found, push the value of ans[i] into the result array
                res[id++] = i;
                found = true;
                // no need to check further, move to the next number
                break;
            }
        }

        // if no valid ans[i] was found, push -1 to indicate it's not possible
        if (!found) {
            res[id++] = -1;
        }
    }

    // return the constructed ans array
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
    // vector<int> nums = {2, 3, 5, 7};

    vector<int> nums = {11, 13, 31};
    vector<int> res = minBitwiseArray(nums);
    printVector(res);
    return 0;
}
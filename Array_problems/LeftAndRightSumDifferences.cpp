
// Problem link - https://leetcode.com/problems/left-and-right-sum-differences/description/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<int> leftRightDifference(vector<int>& nums) {
    int n = nums.size();

    // store result in `answer`
    vector<int> answer(n, 0);

    // step 1 - calculate total sum of array elements
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    // store left sum in `leftSum`
    int leftSum = 0;

    // step 2 - iterate on nums and calculate difference
    for (int i = 0; i < n; i++) {
        // step 3 - calculate right sum 
        int rightSum = totalSum - leftSum - nums[i];

        // step 4 - calculate absolute difference in answer
        answer[i] = abs(leftSum - rightSum);

        // step 5 - calculate left sum
        leftSum += nums[i];
    }

    // step 6 - return `answer` array
    return answer;
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
    // vector<int> nums = {10,4,8,3};

    vector<int> nums = {1};
    vector<int> res = leftRightDifference(nums);
    printVector(res);
    return 0;
}
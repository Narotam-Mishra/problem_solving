
// Problem link - https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

// utlity function to find sum of array's elements digit sum
int findDigitSum(vector<int>& arr){
    int digitSum = 0;
        for (int num : arr) {
            if (num <= 9) {
                digitSum += num;
            } else {
                while (num > 0) {
                    digitSum += num % 10;
                    num = num / 10;
                }
            }
        }
        return digitSum;
}

// utlity function to find sum of array's elements
int findArraySum(vector<int>& arr){
    int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        return sum;
}

int differenceOfSum(vector<int>& nums) {
    // step 1 - get array's element sum
    int elementSum = findArraySum(nums);

    // step 2 - get array's digit sum
    int digitSum = findDigitSum(nums);

    // step 3 - find and return the absolute difference between the element sum and digit sum
    return abs(elementSum - digitSum);
}

int main(){
    // vector<int> nums = {1,15,6,3};

    vector<int> nums = {1,2,3,4};
    cout<<differenceOfSum(nums)<<endl;
    return 0;
}
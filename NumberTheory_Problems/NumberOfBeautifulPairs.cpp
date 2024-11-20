
// Problem link : https://leetcode.com/problems/number-of-beautiful-pairs/description/?envType=problem-list-v2&envId=number-theory&status=TO_DO&difficulty=EASY
#include<bits/stdc++.h>
using namespace std;

// helper function to extract the first digit of a number
int getFirstDigit(int num) {
    while (num >= 10) {
        num = num / 10;
    }
    return num;
}

// helper function to extract the last digit of a number
int getLastDigit(int num) {
    return num % 10;
}

// helper function to calculate the greatest common divisor (GCD) using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int countBeautifulPairs(vector<int>& nums) {
    // initialize count of beautiful pairs
    int count = 0;

    // iterate over all pairs of indices (i, j) where i < j
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            // extract the first digit of nums[i] and the last digit of nums[j]
            int x = getFirstDigit(nums[i]);
            int y = getLastDigit(nums[j]);

            // check if pair are coprime
            if (gcd(x, y) == 1) {
                // increment count if the pair is beautiful
                count++;
            }
        }
    }
    return count;
}

int main(){
    // vector<int> nums = {2, 5, 1, 4};

    vector<int> nums = {11, 21, 12};
    cout<<countBeautifulPairs(nums);
    return 0;
}
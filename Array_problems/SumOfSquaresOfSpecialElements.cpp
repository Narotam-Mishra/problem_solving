
#include<bits/stdc++.h>
using namespace std;

int sumOfSquares(vector<int>& nums) {
    // intialize a variable to store the sum of squares
    int ss = 0;

    // calculate length of array
    int n = nums.size();

    // iterate over array elements
    for (int i = 1; i <= sqrt(n); i++) {
        // check for special elements
        if (n % i == 0) {
            // find sum of squares if it is special element
            ss += (nums[i - 1] * nums[i - 1]);

            // n / i is also a divisor, but avoid double counting when i == n / i
            if (i != n / i) {
                ss += (nums[n / i - 1] * nums[n / i - 1]);
            }
        }
    }

    // return sum of squares `ss`
    return ss;
}
int main(){
    // test case 1
    vector<int> nums = {1, 2, 3, 4};

    // test case 2
    // vector<int> nums = {2, 7, 1, 19, 18, 3};
    cout <<sumOfSquares(nums)<<endl;
    return 0;
}

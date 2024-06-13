
// Problem link - https://leetcode.com/problems/plus-one/

#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    // Start from the end of the array (least significant digit)
    for (int i = digits.size() - 1; i >= 0; i--) {
        // If the current digit is less than 9, we can simply increment it by one
        if (digits[i] < 9) {
            digits[i]++;
            // No further carry, we can return the result
            return digits;
        }

        // If the current digit is 9, set it to 0 and continue to the next significant digit
        digits[i] = 0;
    }

    // If we have processed all digits and still have a carry, create a new vector
    // Insert 1 at the beginning
    digits.insert(digits.begin(), 1);
    return digits;
}

int main(){
    // vector<int> digits = {1, 2, 3};

    vector<int> digits = {9, 9, 9};
    vector<int> res = plusOne(digits);

    for(int digit : digits){
        cout<<digit<<" ";
    }
    cout<<endl;
    return 0;
}
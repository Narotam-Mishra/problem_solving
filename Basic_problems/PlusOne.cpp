
// Problem link - https://leetcode.com/problems/plus-one/

#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne1(vector<int>& digits) {
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

vector<int> plusOne(vector<int>& digits) {
    // find size of digits
    int n = digits.size();

    // step 1 - iterate on digits from LSB and perform operation
    int i = n-1;
    while(i >= 0){
        // check if digit is less than 9
        if(digits[i] < 9){
            // simply increment by 1
            digits[i] += 1;
            return digits;
        }

        // check if digit is 9 than, add carry
        digits[i] = 0;
        i--;
    }

    // step 2 - corner case
    // if we have processed all digits and still have a carry, add that carry in start
    digits.insert(digits.begin(), 1);

    // step 3 - return final result from digits
    return digits;
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
    vector<int> digits = {1, 2, 3};

    // vector<int> digits = {9, 9, 9};
    vector<int> res = plusOne(digits);
    printVector(res);
    return 0;
}
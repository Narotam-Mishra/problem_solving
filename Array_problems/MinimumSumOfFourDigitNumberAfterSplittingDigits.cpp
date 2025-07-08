
// Problem link - https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

#include<bits/stdc++.h>
using namespace std;

int minimumSum(int num) {
    // step 1 - extract all digits from the number
    string numStr = to_string(num);

    // convert to string to easily access individual digits
    vector<int>digits;
    for (char ch : numStr) {
        digits.push_back(ch - '0');
    }

    // step 3 - sort digits in ascending order, this will ensure minimum sum
    sort(digits.begin(), digits.end());

    // step 4 - build two 2-digit numbers
    int num1 = digits[0] * 10 + digits[2];
    int num2 = digits[1] * 10 + digits[3];

    // step 5 - return the sum
    return num1 + num2;
}

int main(){
    // int num = 2932;

    int num = 4009;
    cout<<minimumSum(num)<<endl;
    return 0;
}
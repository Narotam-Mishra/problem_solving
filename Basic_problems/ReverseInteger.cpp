
// Problem link - https://leetcode.com/problems/reverse-integer/

#include<bits/stdc++.h>
using namespace std;

int reverse(int x){
    // check for negativity of number
    bool isNegative = x < 0;

    // Using long to handle overflow
    long reversedNum = 0;

    x = abs(x);

    // reverse number logic
    while (x > 0){
        reversedNum = reversedNum * 10 + x % 10;
        x = x / 10;
    }

    // if the number is negative
    if (isNegative)
        reversedNum *= -1;

    // check for overflow of number
    if (reversedNum < numeric_limits<int>::min() || reversedNum > numeric_limits<int>::max()){
        return 0;
    }

    // return reversed number
    return int(reversedNum);
}

int main(){
    cout << reverse(123) << endl; // Output: 321
    cout << reverse(-123) << endl; // Output: -321
    cout << reverse(120) << endl; // Output: 21
    cout << reverse(1534236469) << endl; // Output: 0 (overflow)
    return 0;
}
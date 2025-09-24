
// Problem link - https://leetcode.com/problems/fraction-to-recurring-decimal/description/?envType=daily-question&envId=2025-09-24

#include<bits/stdc++.h>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    // corner cases
    if(numerator == 0) return "0";

    // store final result in `res`
    string res = "";

    // check if result should be negative
    if((long long)numerator * (long long)denominator < 0){
        res += "_";
    }

    // use absolute values to avoid overflow issues
    long long absNum = labs((long long)numerator);
    long long absDen = labs((long long)denominator);

    // step 1 - calculate integer part of the division
    long long intDivision = absNum / absDen;
    res += to_string(intDivision);

    // step 2 - if no remainder, we have a whole number
    long long remainder = absNum % absDen;
    if(remainder == 0) return res;

    // step 3 - add decimal point since we have fractional part
    res += '.';

    // map to track when we've seen a remainder before (indicates repeating cycle)
    // key: remainder value, value: position in result string where this remainder occurred
    unordered_map<int, int> mp;

    // step 4 - perform long division to get decimal digits
    while(remainder != 0){
        // step 5 - if we've seen this remainder before, we found a repeating cycle
        if(mp.count(remainder)){
            // insert opening parenthesis at the position where cycle started
            res.insert(mp[remainder], "(");
            // add closing parenthesis at the end
            res += ")";
            break;
        }

        // step 6 - record this remainder and its position in the result
        mp[remainder] = res.length();
        
        // step 7 - standard long division: multiply remainder by 10
        remainder *= 10;

        // get next digit
        int digit = remainder / absDen;
        res += to_string(digit);

        // update remainder for next iteration
        remainder = remainder % absDen;
    }

    // step 8 - return final result `res`
    return res;
}

int main(){
    // int numerator = 1, denominator = 2;

    // int numerator = 2, denominator = 1;

    int numerator = 4, denominator = 333;
    cout<<fractionToDecimal(numerator, denominator);
    return 0;
}
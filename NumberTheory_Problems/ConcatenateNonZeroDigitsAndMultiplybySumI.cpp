
// Problem link - https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/?envType=daily-question&envId=2026-07-07&__cf_chl_f_tk=AIXUgrEVBvRtT74DjzgeO1xUlmN6xI7lkLbLJCGh7Fw-1783435511-1.0.1.1-5MJbbC59g.k5RJmPCvWbE9jCCFVxA84SoYB0ceFEUxQ

#include<bits/stdc++.h>
using namespace std;

// utility function to find digits sum
int findDigitsSum(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n = n / 10;
    }
    return s;
}

long long sumAndMultiply(int n) {
    // step 1 - convert number to string
    string num = to_string(n);
    string temp = "";

    // step 2 - concate digits in same order
    for (char ch : num) {
        if (ch != '0') {
            temp += ch;
        }
    }

    // handles n = 0, 1000, 000, etc.
    if (temp.empty()) {
        return 0;
    }

    // step 3 - convert back to number
    long long value = stoll(temp);

    // step 4 - find final result and return
    return value * findDigitsSum(value);
}

int main(){
    int n = 10203004;
    cout<<sumAndMultiply(n);
    return 0;
}
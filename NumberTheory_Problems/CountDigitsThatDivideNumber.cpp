
#include<bits/stdc++.h>
using namespace std;

int countDigits(int num) {
    // intialize counter 'count' to keep track of count
    int count = 0;

    // conver to string for easy iteration
    string numStr = to_string(num);

    // iterate through each digit of string format number
    for (int i = 0; i < numStr.size(); i++) {
        // change digit to number
        int digit = numStr[i] - '0';

        if (digit != 0 && num % digit == 0) {
            // if each non-zero digit divde the number 'num', 
            // increment count
            count++;
        }
    }
    // return the resultant counter 'count'
    return count;
}

int main(){
    // int num = 1248;

    int num = 123;
    cout<<countDigits(num);
    return 0;
}
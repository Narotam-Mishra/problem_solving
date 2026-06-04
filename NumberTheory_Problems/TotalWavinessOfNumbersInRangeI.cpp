
// Problem link - https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/description/?envType=daily-question&envId=2026-06-04

#include<bits/stdc++.h>
using namespace std;

int getWaviness(int num){
    //step 1 - extract each digit from num and store into `digits`
    vector<int> digits;
    while(num > 0){
        digits.push_back(num%10);
        num = num/10;
    }

    // step 2 - reverse digits to get original order
    reverse(digits.begin(), digits.end());

    // find digits size
    int len = digits.size();

    // step 3 - iterate only over middle digits (index 1 to len-2)
    int waviness = 0;
    for(int i=1; i<len-1; i++){
        // extract digit
        int prevDigit = digits[i-1];
        int currDigit = digits[i];
        int nextDigit = digits[i+1];

        // check peak
        bool isPeak = (currDigit > prevDigit) && (currDigit > nextDigit);

        // check valley
        bool isValley = (currDigit < prevDigit) && (currDigit < nextDigit);

        // each peak or valley contributes +1 to waviness
        if(isPeak || isValley) waviness++;
    }

    // return waviness count
    return waviness;
}

int totalWaviness(int num1, int num2) {
    // keep track of waviness count
    int wavinessCount = 0;

    // step 1 - iterate through every number in [num1, num2] inclusive
    for(int num=num1; num<=num2; num++){
        // step 2 - find waviness count
        wavinessCount += getWaviness(num);
    }

    // step 3 - return waviness count
    return wavinessCount;
}

int main(){
    // int num1 = 120, num2 = 130;

    // int num1 = 198, num2 = 202;

    int num1 = 4848, num2 = 4848;
    cout<<totalWaviness(num1, num2);
    return 0;
}
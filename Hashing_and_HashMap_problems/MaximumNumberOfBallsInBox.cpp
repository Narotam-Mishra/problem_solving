
// Problem link : https://leetcode.com/problems/maximum-number-of-balls-in-a-box/description/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

// utlity function to find sum of digits
int findSumOfDigits(int num){
    int sum = 0;
    while(num > 0){
        sum += num % 10;
        num = num/10;
    }
    return sum;
}

int countBalls(int lowLimit, int highLimit) {
    // step 1 - box map array to store the count of balls in each box
    vector<int> boxMapArr(46, 0);

    // step 2 - iterate through all ball numbers
    for(int i=lowLimit; i<=highLimit; i++){
        int boxNumber = findSumOfDigits(i);

        // update the count in box map array
        boxMapArr[boxNumber]++;
    }

    // step 3 - find the maximum number of balls in any box and return its value
    return *max_element(boxMapArr.begin(), boxMapArr.end());
}

int main(){
    // int lowLimit = 1, highLimit = 10;

    // int lowLimit = 5, highLimit = 15;

    int lowLimit = 19, highLimit = 28;
    cout<<countBalls(lowLimit, highLimit)<<endl;
    return 0;
}
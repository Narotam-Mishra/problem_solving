
// Problem link : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

int numberOfSteps(int num) {
    // edge case:
    if (num == 0) return 0;

    int res = 0;
    // loop until num becomes 0
    while (num > 0) {
        // if num is odd, subtract 1
        // otherwise if num is even, divide it by 2
        if ((num & 1) == 1) {
            num--;
        }
        else {
            num /= 2;
        }
        res++;
    }
    // return the total number of steps taken
    return res;
}

int main(){
    int num = 123;
    cout<<numberOfSteps(num);
    return 0;
}
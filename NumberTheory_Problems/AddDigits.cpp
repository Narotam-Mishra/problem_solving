
// Problem link - https://leetcode.com/problems/add-digits/description/?envType=problem-list-v2&envId=number-theory

#include<bits/stdc++.h>
using namespace std;

int findDigitsSum(int num){
    int s = 0;
    while(num > 0){
        s += num % 10;
        num = num/10;
    }
    return s;
}

int addDigits(int num) {
    while(num >= 10){
        num = findDigitsSum(num);
    }
    return num;
}

int main(){
    // int num = 199;

    int num = 38;
    cout<<addDigits(num);
    return 0;
}
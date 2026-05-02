
// Problem link - https://leetcode.com/problems/rotated-digits/description/?envType=daily-question&envId=2026-05-02

#include<bits/stdc++.h>
using namespace std;

// utility method to check if number is Good number
bool isGoodNumber(int num){
    bool canChange = false;

    while(num > 0){
        int d = num % 10;
        // check for non-good digits 3,4,7
        if(d == 3 || d == 4 || d == 7) return false;

        // check bood digits
        if(d == 2 || d == 5 || d == 6 || d == 9){
            canChange = true;
        }

        // extract next digit
        num = num / 10;
    }

    // return true or false 
    return canChange;
}

int rotatedDigits(int n) {
    // counter to keep track of good integers
    int count = 0;

    // step 1 - iterate of each number from 1 to num
    for(int num=1; num <= n; num++){
        // step 2 - check for good integers
        if(isGoodNumber(num)){
            // increment count
            count++;
        }
    }

    // step 3 - return counter, `count`
    return count;
}

int main(){
    // int n = 10;

    // int n = 1;
    
    int n = 2;
    cout<<rotatedDigits(n);
    return 0;
}
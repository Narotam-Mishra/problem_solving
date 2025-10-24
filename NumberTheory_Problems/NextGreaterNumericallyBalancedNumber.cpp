
// Problem link - https://leetcode.com/problems/next-greater-numerically-balanced-number/description/?envType=daily-question&envId=2025-10-24

#include<bits/stdc++.h>
using namespace std;

// utility function to check if number is Balanced or not
bool isBalancedNumber(int num){
    vector<int> freq(10, 0);

    while(num > 0){
        int digit = num % 10;
        freq[digit]++;
        num = num / 10;
    }

    for(int d=0; d<10; d++){
        if(freq[d] > 0 && freq[d] != d){
            return false;
        }
    }
    return true;
}

int nextBeautifulNumber1(int n) {
    // step 1 - iterate from n+1 to last balanced number in given range
    for(int i=n+1; i<=1224444; i++){

        // step 2 - check if the number is balanced or not
        if(isBalancedNumber(i)){
            // step 3 - return the balanced number immediately
            return i;
        }
    }

    // otherwise return -1;
    return -1;
}

int backtrack(vector<int>& digitCount, int n, int curr, int digitsLeft){
    // base case:
    if(digitsLeft == 0){
        for(int d=1; d<10; d++){
            if(digitCount[d] != 0 && digitCount[d] != d){
                return 0;
            }
        }
        return curr > n ? curr : 0;
    }

    int res = 0;
    for(int d=1; d<10; d++){
        if(digitCount[d] > 0 && digitCount[d] <= digitsLeft){
            digitCount[d]--;

            res = backtrack(digitCount, n, curr*10+d, digitsLeft-1);
            
            digitCount[d]++;
        }
        
        if(res != 0) break; 
    }
    return res;
}

int nextBeautifulNumber(int n) {
    vector<int> digitCount{0,1,2,3,4,5,6,7,8,9};
    
    int numDigits = to_string(n).length();

    int res = backtrack(digitCount, n, 0, numDigits);

    if(res == 0){
        res = backtrack(digitCount, n, 0, numDigits+1);
    }
    return res;
}

int main(){
    int n = 1;

    // int n = 1000;

    // int n = 3000;
    cout<<nextBeautifulNumber(n);
    return 0;
}
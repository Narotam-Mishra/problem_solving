
// Problem link - https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/?envType=daily-question&envId=2025-12-07

#include<bits/stdc++.h>
using namespace std;

int countOdds(int low, int high) {
    // step 1 - calculate total number in range
    int totalNums = high - low + 1;

    // step 2 - check if low is odd, we need ceiling of (totalNumbers / 2)
    // if low is even, we need floor of (totalNumbers / 2)
    if (low % 2 == 1) {
        return (totalNums + 1) / 2;
    }
    else {
        return totalNums / 2;
    }
}

int main(){
    // int low = 3, high = 7;

    int low = 8, high = 10;
    cout<<countOdds(low, high);
    return 0;
}
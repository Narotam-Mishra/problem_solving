
// Problem link - https://www.naukri.com/code360/problems/equal-first-digit-and-last-digit_4607860

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// utility function to count numbers from 1 to num where first digit equals last digit
ll countUpto(ll num){
    // step 1 - handle single digit numbers (1-9) 
    // all have equal first and last digit
    if(num < 10) return num;

    // step 2 - calculate count from numbers with 2 or more digits
    ll tens = num / 10;  

    // step 3: add 9 (for single digits 1-9) + tens (numbers like 11,22,...,99,101,111,.....)
    ll ans = tens + 9;

    // step 4 - convert num to string to check first and last digits
    string s = to_string(num);
    
    // step 5 - check if last digit is smaller than first digit, 
    // then we need to exclude num from our count
    if(s.back() < s.front()){
        ans--;
    }

    // return final answer, `ans`
    return ans;
}

ll equalDigit(ll l, ll r) {
    // calculate: (count up to r) - (count up to l-1)
    return countUpto(r) - countUpto(l-1);
}

int main(){
    // ll l = 9, r = 12;

    ll l = 47, r = 74;
    cout<<equalDigit(l, r);
    return 0;
}
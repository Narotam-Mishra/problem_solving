
#include<bits/stdc++.h>
using namespace std;

bool hasSameDigits(string s) {
    // step 1 - convert the string into an array of digits
    vector<int> digits;
    for(char ch : s){
        digits.push_back(ch - '0');
    }

    // step 2 - keep reducing the array until only two digits remain
    int n = digits.size();
    while(n > 2){
        // step 3 - compute new digits based on adjacent pairs
        for(int i=0; i<n-1; i++){
            digits[i] = (digits[i] + digits[i+1]) % 10;
        }

        // step 4 - reduce the effective length of the array
        n--;
    }

    // step 5 - check if the final two digits are equal or not
    return digits[0] == digits[1];
}

int main(){
    // string s = "3902";

    string s = "34789";
    bool res = hasSameDigits(s);
    res ? cout<<"true" : cout<<"false";
    return 0;
}
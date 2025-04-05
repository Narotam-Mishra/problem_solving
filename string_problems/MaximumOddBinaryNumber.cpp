
// Problem link - https://leetcode.com/problems/maximum-odd-binary-number/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string maximumOddBinaryNumber(string s) {
    // step 1 - count ones in binary string
    int countOnes = 0;
    for(char ch : s){
        if(ch == '1'){
            countOnes++;
        }
    }

    // step 2 - find number of zeroes in `s`
    int countZeroes = s.size() - countOnes;

    // step 3 - rearrange binary numbers to from maximum odd binary number
    string res = string(countOnes - 1, '1') + string(countZeroes, '0') + '1';

    // step 4 - return `res`
    return res;
}

int main(){
    // string s = "010";

    string s = "0101";
    cout<<maximumOddBinaryNumber(s)<<endl;
    return 0;
}
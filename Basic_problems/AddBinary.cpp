
// Problem link - https://leetcode.com/problems/add-binary/description/

#include<bits/stdc++.h>
using namespace std;


string addBinary(string a, string b) {
    // store sum result into 'res'
    string res = "";
    // store digits sum to 's'
    int s = 0;

    // initialize two indices for a and b
    int i = a.size() - 1, j = b.size() - 1;
    while(i >= 0 || j >= 0 || s == 1){
        // compute the sum of the current digits and the carry
        s += (i >= 0) ? a[i] - '0' : 0;
        s += (j >= 0) ? b[j] - '0' : 0;

        // if current digit sum is 1 or 3, add 1 to result
        res = char(s % 2 + '0') + res;

        // compute carry
        s = s/2;

        // move i and j
        i--;
        j--;
    }

    // return result 'res'
    return res;
}

int main(){
    string a = "1010";
    string b = "1011";

    cout<<addBinary(a, b)<<endl;
    return 0;
}
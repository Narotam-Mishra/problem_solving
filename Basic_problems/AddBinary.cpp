
// Problem link - https://leetcode.com/problems/add-binary/description/

#include<bits/stdc++.h>
using namespace std;

string addBinary1(string a, string b) {
    // store sum result into 'res'
    string res = "";

    // store digits sum to 's'
    int s = 0;

    // initialize two indices for a and b
    int i = a.size() - 1, j = b.size() - 1;

    // step 1 - iterate on both input strings
    while(i >= 0 || j >= 0 || s == 1){
        // step 2 - compute the sum of the current digits and the carry
        s += (i >= 0) ? a[i] - '0' : 0;
        s += (j >= 0) ? b[j] - '0' : 0;

        // step 3 - if current digit sum is 1 or 3, add 1 to result
        res = char(s % 2 + '0') + res;

        // step 4 - compute carry
        s = s/2;

        // step 5 - move i and j
        i--;
        j--;
    }

    // step 6 - return result 'res'
    return res;
}

string addBinary(string a, string b) {
    // final length of both strings `a` and `b`
    int m = a.length()-1, n = b.length()-1;

    // keep track of result in `res`
    string res = "";

    // keep track of sum and carry
    int sum = 0, carry = 0;

    // step 1 - iterate on both strings
    while(m>=0 || n>=0){
        // assign carry to sum
        sum = carry;

        // step 2 - calculate sum
        if(m >= 0){
            sum += a[m] - '0';
            m--;
        }

        if(n >= 0){
            sum += b[n] - '0';
            n--;
        }

        // step 3 - store sum into `res`
        res.push_back((sum % 2 == 0) ? '0' : '1');

        // step 4 - update carry
        carry = (sum > 1) ? 1 : 0;
    }

    // step 5 - check if carry exist in end
    if(carry){
        // then add to result
        res.push_back('1');
    }

    // step 6 - reverse result `res`
    reverse(res.begin(), res.end());

    // step 7 - return finsl result, `res`
    return res;
}

int main(){
    // string a = "1010";
    // string b = "1011";

    string a = "11";
    string b = "1";

    cout<<addBinary(a, b)<<endl;
    return 0;
}

// Problem link : https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

string toHex(int num) {
    // handle the edge case for 0
    if(num == 0) return "0";

    // handle negative numbers using two's complement
    unsigned int n = num;
    stringstream ss;
    
    // convert to hexadecimal string
    ss<<hex<<n;

    return ss.str();
}

int main(){
    // int num = 26;

    int num = -1;
    cout<<toHex(num);
}
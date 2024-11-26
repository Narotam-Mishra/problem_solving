
#include<bits/stdc++.h>
using namespace std;

// helper function to find GCD of two numbers
int findGCD(int a, int b){
    return b == 0 ? a : findGCD(b, a % b);
}
string gcdOfStrings(string str1, string str2) {
    // step 1: check if concatenated strings are equal
    if (str1 + str2 != str2 + str1) {
        return "";
    }

    // step 2: calculate GCD of lengths
    int gcdLen = findGCD(str1.length(), str2.length());

    // step 3: the GCD string is the prefix of either string of length gcdLen
    return str1.substr(0, gcdLen);
}
int main(){
    // string str1 = "ABCABC", str2 = "ABC";

    // string str1 = "ABABAB", str2 = "ABAB";

    string str1 = "LEET", str2 = "CODE";
    cout<<gcdOfStrings(str1, str2)<<endl;
    return 0;
}
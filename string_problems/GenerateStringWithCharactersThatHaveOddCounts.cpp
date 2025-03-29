
// Problem link - https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string generateTheString(int n) {
    // step 1 - if `n` is odd then generate `n` characters
    // step 2 - if `n` is even then generate `n-1` characters first and one different character
    return (n % 2 == 1) ? string(n, 'a') : string(n-1, 'a') + 'b';
}

int main(){
    // int n = 4;

    // int n = 2;

    int n = 7;
    cout<<generateTheString(n)<<endl;
    return 0;
}
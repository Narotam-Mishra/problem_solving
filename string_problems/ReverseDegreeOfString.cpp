
// Problem link - https://leetcode.com/problems/reverse-degree-of-a-string/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int reverseDegree(string s) {
    // step 1 - initialize variable to store reverse degree `rd`
    int rd = 0;

    // step 2 - iterate on each character of `s`
    for(int i=0; i<s.size(); i++){
        // step 3 - calculate the reverse position in the alphabet
        int revPos = 26 - (s[i] - 'a');

        // step 4 - multiply with the 1-indexed position in the string
        rd += revPos * (i + 1);
    }

    // step 5 - return reverse degree `rd`
    return rd;
}

int main(){
    // string s = "abc";

    string s = "zaza";
    cout<<reverseDegree(s)<<endl;
    return 0;
}
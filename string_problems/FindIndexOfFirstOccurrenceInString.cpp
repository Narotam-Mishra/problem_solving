
#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
    // base case: check if needle is empty or not
    if (needle.empty()) return 0;

    // using find() function to find first occurrence
    size_t index = haystack.find(needle);

    return (index != string::npos) ? index : -1;
}

int main(){
    string haystack = "sadbutsad", needle = "sad";
    cout<<strStr(haystack, needle);
    return 0;
}
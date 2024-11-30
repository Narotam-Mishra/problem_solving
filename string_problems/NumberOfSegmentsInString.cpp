
// Problem link : https://leetcode.com/problems/number-of-segments-in-a-string/description/?envType=problem-list-v2&envId=string&favoriteSlug=&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

int countSegments(string s) {
    // step 1: trim leading and trailing spaces
    // using built-in functions to simplify this
    
    // trim leading spaces from string s
    s.erase(0, s.find_first_not_of(" "));

    // trim trailing spaces from string s
    s.erase(s.find_last_not_of(" ") + 1);

    // step 2: handle empty string case
    if(s.empty()) return 0;

    // step 3: use stringstream to split by spaces
    stringstream ss(s);
    string segment;
    int count = 0;

    // automatically skips multiple spaces
    while(ss >> segment){
        count++;
    }

    // return valid string segment count
    return count;
}

int main(){
    // string str = "Hello, my name is John";

    string str = "Hello";
    cout<<countSegments(str)<<endl;
    return 0;
}
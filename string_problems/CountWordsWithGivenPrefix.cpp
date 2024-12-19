
#include<bits/stdc++.h>
using namespace std;

int prefixCount(vector<string>& words, string pref) {
    // intialize counter `countPrefix` to count number of prefix exist in words array
    int countPrefix = 0;

    // step 1 - iterate through words array
    for (string word : words) {
        // step 2 - check if prefix exists
        if(word.substr(0, pref.size()) == pref){
            // step 3 - increment the prefix count
            countPrefix++;
        }
    }

    // step 4 - return `countPrefix` counter
    return countPrefix;
}

int main(){
    // vector<string> words = {"pay","attention","practice","attend"};
    // string pref = "at";

    vector<string> words = {"leetcode","win","loops","success"};
    string pref = "code";
    cout<<prefixCount(words, pref)<<endl;
    return 0;
}
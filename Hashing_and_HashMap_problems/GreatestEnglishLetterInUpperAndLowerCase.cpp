
#include<bits/stdc++.h>
using namespace std;

string greatestLetter(string s) {
    // step 1: create an unordered_set to store characters in the string
    unordered_set<char> charSet(s.begin(), s.end());

    // step 2: iterate from 'z' to 'a' and check if both lowercase and uppercase exist
    for (char ch = 'z'; ch >= 'a'; ch--) {
        if (charSet.count(ch) && charSet.count(toupper(ch))) {
            return string(1, toupper(ch));
        }
    }

    // step 3: if no valid letter is found, return an empty string
    return "";   
}

int main(){
    // string s = "lEeTcOdE";

    // string s = "arRAzFif";

    string s = "AbCdEfGhIjK";
    cout<<greatestLetter(s)<<endl;
    return 0;
}
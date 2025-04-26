
// Problem link - https://leetcode.com/problems/count-asterisks/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int countAsterisks(string s) {
    // step 1 - initialize counter to count `*`
    int count = 0;

    // step 2 - track whether we are inside `|` pair or not
    bool insidePair = false;

    // step 3 - iterate on each character of input `s`
    for (char ch : s) {
        if (ch == '|') {
            // step 4 - toggle the insidePair flag whenever we see `|`
            insidePair = !insidePair;
        } else if (ch == '*' && !insidePair) {
            // step 5 - only count `*` if we are outside of `|` pair
            count++;
        }
    }

    // step 6 - return count
    return count;
}

int main(){
    // string s = "l|*e*et|c**o|*de|";

    // string s = "iamprogrammer";

    string s = "yo|uar|e**|b|e***au|tifu|l";
    cout<<countAsterisks(s)<<endl;
    return 0;
}

// Problem link : https://leetcode.com/problems/long-pressed-name/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

bool isLongPressedName(string name, string typed) {
    // using two-pointers approach
    // pointer 'i' for name
    int i = 0;

    // pointer 'j' for typed
    int j = 0;

    // traverse through typed characters
    while (j < typed.size()) {
        // case 1 : character match case in both name and typed strings
        if (i < name.size() && name[i] == typed[j]) {
            i++;
            j++;
            // case 2 : long-pressed scneario
        }
        else if (j > 0 && typed[j] == typed[j - 1]) {
            j++;
            // case 3 : invalid scenario, character in typed doesn't match
        }
        else {
            // name's current character or isn't a long press
            return false;
        }
    }

    // after processing typed, ensure all characters in name matched
    return i == name.size();
}

int main(){
    // string name = "alex", typed = "aaleex";

    string name = "saeed", typed = "ssaaedd";
    bool res = isLongPressedName(name, typed);
    res ? cout<<"true" : cout<<"false"<<endl;
    return 0;
}
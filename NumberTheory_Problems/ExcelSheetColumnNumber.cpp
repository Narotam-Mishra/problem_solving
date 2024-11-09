
// Problem link : https://leetcode.com/problems/excel-sheet-column-number/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

int titleToNumber(string columnTitle) {
    // intialize columnNumber to 0 and store actual result in it,
    int columNumber = 0;

    // iterate on each character of column title
    for(char ch : columnTitle){
        // shift columnNumber up by 26 for the new place
        columNumber *= 26;

        // add the value of the current character (A=1, B=2, ..., Z=26)
        columNumber += ch - 'A' + 1;
    }

    // return actual result
    return columNumber;
}

int main(){
    // string ct = "A";

    // string ct = "AB";

    // string ct = "ZY";

    string ct = "ABD";
    cout<<titleToNumber(ct);
    return 0;
}


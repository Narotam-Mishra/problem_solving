
// Problem link : https://leetcode.com/problems/excel-sheet-column-title/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

string convertToTitle(int columnNumber) {
    string title;

    while(columnNumber > 0){
        // for adjusting for 1-based indexing
        columnNumber--;

        // calculate the current letter
        char letter = (columnNumber % 26) + 'A';

        // prepend the letter to the title
        title = letter + title;

        // move to the next position
        columnNumber /= 26;
    }
    return title;
}

int main(){
    // int columnNumber = 1;

    // int columnNumber = 26;

    // int columnNumber = 27;

    int columnNumber = 28;
    cout<<convertToTitle(columnNumber);
    return 0;
}
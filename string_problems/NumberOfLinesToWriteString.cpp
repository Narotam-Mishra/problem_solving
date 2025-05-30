
// Problem link - https://leetcode.com/problems/number-of-lines-to-write-string/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> numberOfLines(vector<int>& widths, string s) {
    // step 1 - start with first line and initialize current width
    int lines = 1, currentWidth = 0;

    // step 2 - iterate on each character of string `s`
    for (char ch : s) {
        // step 3 - find corresponding width of current character
        int charWidth = widths[ch - 'a'];

        // step 4 - check if adding this character would exceed the line limit
        if (charWidth + currentWidth > 100) {
            // start new line
            lines++;
            currentWidth = charWidth;
        }
        else {
            // otherwise add character to current line
            currentWidth += charWidth;
        }
    }

    // step 5 - return [total number of lines, width of the last line]
    return vector<int>{lines, currentWidth};
}

void printVector(vector<int>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    // vector<int> widths = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    // string s = "abcdefghijklmnopqrstuvwxyz";

    vector<int> widths = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string s = "bbbcccdddaaa";
    vector<int> res = numberOfLines(widths, s);
    printVector(res);
    return 0;
}
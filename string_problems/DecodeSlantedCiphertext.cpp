
// Problem link - https://leetcode.com/problems/decode-the-slanted-ciphertext/description/?envType=daily-question&envId=2026-04-04

#include<bits/stdc++.h>
using namespace std;

string decodeCiphertext(string encodedText, int rows) {
    int len =encodedText.length();

    // step 1 - find number of column
    int col = len / rows;

    // step 2 - iterate on encoded string diagonally
    string originalText = "";
    for(int c=0; c<col; c++){
        for(int j=c; j<len; j+= (col+1)){
            // step 3 - prepare original string
            originalText += encodedText[j];
        }
    }

    // step 4 - extract trailing spaces
    while (!originalText.empty() && originalText.back() == ' '){
        originalText.pop_back();
    }

    // step 5 - return original string
    return originalText;
}

int main(){
    // string encodedText = "ch   ie   pr";
    // int rows = 3;

    // string encodedText = "iveo    eed   l te   olc";
    // int rows = 4;

    string encodedText = "coding";
    int rows = 1;
    cout<<decodeCiphertext(encodedText, rows);
    return 0;
}
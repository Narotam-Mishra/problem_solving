
// Problem link : https://leetcode.com/problems/minimum-moves-to-convert-string/description/

#include<bits/stdc++.h>
using namespace std;

int minimumMoves(string s) {
    // counter for the number of moves required
    int moves = 0;

    // pointer to iterate through the string
    int i = 0;

    // iterate through the string
    while (i < s.length()) {
        // if we find an 'X', we need to make a move
        if (s[i] == 'X') {
            // make a move, even if some of them are already 'O', it doesn't matter
            moves++;

            // skip the next two characters, as they are included in the current move
            i += 3;
        }
        else {
            // if the character is 'O', just move to the next character
            i++;
        }
    }
    // return the total number of moves required
    return moves;
}

int main(){
    // string str = "XXX";

    // string str = "XXOX";

    string str = "OOOO";
    cout<<minimumMoves(str);
    return 0;
}

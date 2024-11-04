
#include<bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) {
    // removing trailing spaces from string
    string str = s;
    while (!str.empty() && str.back() == ' ') {
        str.pop_back();
    }

    // find the last space index
    size_t lsIdx = str.find_last_of(' ');

    // if no spaces, return the length of the entire string
    if (lsIdx == string::npos) {
        return str.length();
    }

    // return the length of the substring after the last space
    return str.length() - lsIdx - 1;
}

int main(){
    // string str = "Hello World";

    // string str = "   fly me   to   the moon  ";

    string str = "luffy is still joyboy";
    cout<<lengthOfLastWord(str);
    return 0;
}
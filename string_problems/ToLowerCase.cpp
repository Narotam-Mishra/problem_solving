
// Problem link : https://leetcode.com/problems/to-lower-case/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

// string toLowerCase1(string s) {
//     for(char& ch : s){
//         ch = tolower(ch);
//     }
//     return s;
// }

string toLowerCase(string s) {
    string res = "";

    for (char ch : s) {
        // Check if character is uppercase
        if (ch >= 'A' && ch <= 'Z') {
            // Convert to lowercase by adding 32
            res += (ch + 32);
        }
        else {
            res += ch;
        }
    }
    return res;
}

int main(){
    // string str = "Hello World";

    string str = "LOVELY";

    // string str = "here";
    cout<<toLowerCase(str)<<endl;
    return 0;
}
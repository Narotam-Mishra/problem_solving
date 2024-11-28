
#include<bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
    // start from the last digit and move backward
    for (int i = num.length() - 1; i >= 0; i--) {
        // convert the character to a number and check if it's odd
        if ((num[i] - '0') & 1) {
            // if odd, return the substring from the start to this position
            return num.substr(0, i + 1);
        }
    }
    // if no odd digit is found, return an empty string
    return "";
}

int main(){
    // string num = "52";

    // string num = "4206";

    string num = "35427";
    cout<<largestOddNumber(num)<<endl;
    return 0;
}
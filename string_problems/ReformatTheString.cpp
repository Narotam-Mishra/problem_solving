
#include<bits/stdc++.h>
using namespace std;

string reformat(string s) {
    // step 1 - separate letters and digits into two lists
    vector<char> letters;
    vector<char> digits;

    for (char ch : s) {
        if (isalpha(ch)) {
            letters.push_back(ch);
        }
        else if (isdigit(static_cast<unsigned char>(ch))) {
            digits.push_back(ch);
        }
    }

    // step 2 - check if it's impossible to reformat
    if (abs((int)letters.size() - (int)digits.size()) > 1) {
        // return an empty string
        return "";
    }

    // step 3 - decide which group should start
    vector<char>& largerGrp = letters.size() >= digits.size() ? letters : digits;
    vector<char>& smallerGrp = letters.size() < digits.size() ? letters : digits;

    // step 4 - merge alternately
    string res;
    size_t i = 0, j = 0;
    while (i < largerGrp.size() || j < smallerGrp.size()) {
        if (i < largerGrp.size()) res += largerGrp[i++];
        if (j < smallerGrp.size()) res += smallerGrp[j++];
    }

    return res;
}

int main(){
    // string str = "a0b1c2";

    // string str = "leetcode";

    string str = "1229857369";
    cout<<reformat(str)<<endl;
    return 0;
}
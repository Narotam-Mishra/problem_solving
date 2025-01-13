
#include<bits/stdc++.h>
using namespace std;

bool areOccurrencesEqual(string s) {
    // step 1 - create frequency array map and store frequency of each character of input string `s`
    vector<int> frqArr(26, 0);
    for (int i = 0; i < s.length(); i++) {
        frqArr[s[i] - 'a']++;
    }

    // step 2 - get count of first charcter of input string
    int currCount = frqArr[s[0] - 'a'];

    // step 3 - compare 1st charcter count with remaining characters
    for (int num : frqArr) {
        // if remaining characters count are not equal
        if (num != 0 && num != currCount) {
            // return false immediately
            return false;
        }
    }

    // step 4 - otherwise return true
    return true;
}

int main(){
    // string str = "abacbc";

    string str = "aaabb";
    bool res = areOccurrencesEqual(str);
    res ? cout<<"true"<<endl : cout<<"false"<<endl;
    return 0;
}
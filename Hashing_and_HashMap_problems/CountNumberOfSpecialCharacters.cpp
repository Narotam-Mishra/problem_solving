
#include<bits/stdc++.h>
using namespace std;

int numberOfSpecialChars(string word) {
    // step 1 - initialize two sets to store lowercase and uppercase letters
        // to store all uppercase letters
    unordered_set<char> upperSet;

    // to store all lowercase letters
    unordered_set<char> lowerSet;

    // step 2 - populate the sets by iterating through the string `word`
    for (char ch : word) {
        if (ch >= 'a' && ch <= 'z') {
            lowerSet.insert(ch);
        }
        else if (ch >= 'A' && ch <= 'Z') {
            upperSet.insert(ch);
        }
    }

    // step 3 - count special letters
    int specialCharCount = 0;
    for (char ch : lowerSet) {
        // convert lowercase to uppercase
        char upperCh = toupper(ch);
        if (upperSet.find(upperCh) != upperSet.end()) {
            specialCharCount++;
        }
    }

    // step 4 - return the total count of special letters
    return specialCharCount;
}

int main(){
    // string word = "aaAbcBC";

    // string word = "abc";

    string word = "abBCab";
    cout<<numberOfSpecialChars(word)<<endl;
    return 0;
}
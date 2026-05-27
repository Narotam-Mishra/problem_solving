
#include<bits/stdc++.h>
using namespace std;

int numberOfSpecialChars(string word) {
    // get size of word
    int n = word.size();

    // keep track occurance of lowecase & uppercase characters separately
    vector<int> lastLower(26, -1);
    vector<int> firstUpper(26, n);

    // step 1 - iterate through the string to fill both arrays
    for(int i=0; i<n; i++){
        // extract current character
        char ch = word[i];

        // for lower case letter update lastLower
        if(islower(ch)){
            int idx = ch - 'a';
            lastLower[idx] = i;
        }
        else{
            // for upper case letter update firstUpper
            int idx = ch - 'A';
            if(firstUpper[idx] == n){
                firstUpper[idx] = i;
            }
        }
    }

    // keep track of special count
    int specialCount = 0;

    // step 2 - count special characters
    for(int i=0; i<26; i++){
        // case 1 - check if lower case letter exist
        bool lowercaseExist = lastLower[i] != -1;

        // case 2 - check if upper case letter exist
        bool uppercaseExist = firstUpper[i] != n;

        // case 3 - check if last lowercase comes before first uppercase
        bool orderStaisfied = lastLower[i] < firstUpper[i];

        // check above three condiitons
        if(lowercaseExist && uppercaseExist && orderStaisfied){
            // increment special characters count
            specialCount++;
        }
    }

    // step 3 - return special characters count
    return specialCount;
}

int main(){
    // string word = "aaAbcBC";

    // string word = "abc";

    string word = "AbBCab";
    cout<<numberOfSpecialChars(word);
    return 0;
}
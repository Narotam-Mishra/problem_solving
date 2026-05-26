
#include<bits/stdc++.h>
using namespace std;

int numberOfSpecialChars1(string word) {
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

int numberOfSpecialChars(string word) {
    // take fixed size array of 52 to track existence of characters
    int frq[52] = {0};
    
    // step 1 - mark existence of each character in the word
    for(char ch : word){
        if(islower(ch)){
            frq[ch - 'a'] = 1;
        }else{
            frq[ch - 'A' + 26] = 1;
        }
    }

    // keep track of special count
    int cnt = 0;

    // step 2 - check each letter (0-25) if both its lowercase 
    // and uppercase version exist or not
    for(int i=0; i<26; i++){
        // check if both frequencies must be 1 for the letter to be "special"
        if(frq[i] == 1 && frq[i+26] == 1){
            // increment count
            cnt++;
        }
    }

    // step 3 - return total count of special letters
    return cnt;
}

int main(){
    string word = "aaAbcBC";

    // string word = "abc";

    // string word = "abBCab";
    cout<<numberOfSpecialChars(word)<<endl;
    return 0;
}
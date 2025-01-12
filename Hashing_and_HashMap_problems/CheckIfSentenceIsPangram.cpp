
#include<bits/stdc++.h>
using namespace std;

bool checkIfPangram(string sentence) {
    // step 1 - iterate through each letter of the alphabet
    for(char ch = 'a'; ch <= 'z'; ch++){
        // step 2 - check if the current letter is present in the sentence
        if(sentence.find(ch) == string::npos){
            // step 3 - if any letter is not found, return false
            return false;
        }
    }
    // step 4 - if all letters are found, return true
    return true;
}

int main(){
    // string sentence = "thequickbrownfoxjumpsoverthelazydog";

    string sentence = "leetcode";
    bool res = checkIfPangram(sentence);
    res ? cout<<"true" : cout<<"false"<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

string toGoatLatin(string sentence) {
    // define set of vowels
    unordered_set<char> vowels{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

    // split sentence into words 
    vector<string> words;
    istringstream iss(sentence);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }

    // process each word and transform it into GoatLatin as per given conditions
    string res;
    for (int i = 0; i < words.size(); i++) {
        string tw;

        // check if the word starts with a vowel
        if (vowels.count(words[i][0])) {
            // append "ma" if it starts with a vowel
            tw = words[i] + "ma";
        }
        else {
            // if it starts with a consonant, move the first letter to the end and append "ma"
            tw = words[i].substr(1) + words[i][0] + "ma";
        }

        // append 'a' based on the word index
        tw += string(i + 1, 'a');

        // add the transformed word to the result 'res'
        if (!res.empty()) {
            res += " ";
        }
        res += tw;
    }

    return res;
}

int main(){
    // string sentence = "I speak Goat Latin";

    string sentence = "The quick brown fox jumped over the lazy dog";
    cout<<toGoatLatin(sentence)<<endl;
}
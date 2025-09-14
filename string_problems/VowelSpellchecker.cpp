
// Problem link - https://leetcode.com/problems/vowel-spellchecker/description/?envType=daily-question&envId=2025-09-14

#include<bits/stdc++.h>
using namespace std;

// utility method to convert vowels to a pattern (replace vowels with '*')
string getVowelPattern(const string& word){
    string vowelsPatternWord;
    string lowerWord = word;

    // convert to lowercase
    transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

    for(char ch : lowerWord){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            vowelsPatternWord += '*';
        }else{
            vowelsPatternWord += ch;
        }
    }
    return vowelsPatternWord;
}

vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    // step 1 - create required data structures
    // set for exact matches (case sensitive)
    unordered_set<string> exactWords;

    // map for capitalization matches
    unordered_map<string, string> capWords;

    // map for vowel pattern matches 
    unordered_map<string, string> vowelsMap;

    // step 2 - iterate on wordlist and populate map
    for (const string& word : wordlist) {
        // store word for exact matches
        exactWords.insert(word);

        // store first occurrence for capitalization matches
        string lowerWord = word;
        transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
        if (capWords.find(lowerWord) == capWords.end()) {
            capWords[lowerWord] = word;
        }

        // store for vowel pattern matches
        string vowelWordPattern = getVowelPattern(word);
        if (vowelsMap.find(vowelWordPattern) == vowelsMap.end()) {
            vowelsMap[vowelWordPattern] = word;
        }
    }

    // step 3 - process each query according to given precedence rule
    vector<string> res;
    res.reserve(queries.size());

    for (int i = 0; i < queries.size(); i++) {
        string query = queries[i];
        string ans = "";

        // rule1 - check for exact match
        if (exactWords.find(query) != exactWords.end()) {
            ans = query;
        }

        // rule 2 - check for capitalization match (case insensitive)
        else {
            string lowerQuery = query;
            transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);
            if (capWords.find(lowerQuery) != capWords.end()) {
                ans = capWords[lowerQuery];
            }
            // rule 3 - check for vowel error match
            else {
                string queryVowelPattern = getVowelPattern(query);
                if (vowelsMap.find(queryVowelPattern) != vowelsMap.end()) {
                    ans = vowelsMap[queryVowelPattern];
                }
                // rule 4 - for no match, return empty 
                // for which ans is set to ""
            }
        }

        // store result for current query
        res.push_back(ans);
    }

    // step 4 - return final result `res`
    return res;
}

void printVector(vector<string>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    vector<string> wordlist = {"KiTe","kite","hare","Hare"}, queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
    vector<string> res = spellchecker(wordlist, queries);
    printVector(res);
    return 0;
}
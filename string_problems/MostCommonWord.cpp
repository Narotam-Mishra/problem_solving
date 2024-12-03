
#include<bits/stdc++.h>
using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) {
    // step 1 : normalize the paragraph
    string normalizedPara;
    for(char ch : paragraph){
        if(isalnum(ch)){
            normalizedPara += tolower(ch);
        }else{
            normalizedPara += ' ';
        }
    }

    // step 2 : split the paragraph into words by removing extra spaces
    istringstream stream(normalizedPara);
    string word;

    // step 3 : convert banned words to a Set for efficient lookup
    unordered_set<string> bannedWords(banned.begin(), banned.end());

    // step 4 : count the frequency of non-banned words
    unordered_map<string, int> wordCount;
    while(stream >> word){
        if(bannedWords.find(word) == bannedWords.end()){
            wordCount[word]++;
        }
    }

    // step 5 : find the most frequent word
    string mostFrqWord;
    int maxCount = 0;
    for(const auto& entry : wordCount){
        if(entry.second > maxCount){
            mostFrqWord = entry.first;
            maxCount = entry.second;
        }
    }

    return mostFrqWord;
}

int main(){
    // string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    // vector<string> banned = {"hit"};

    string paragraph = "a.";
    vector<string> banned = {};
    cout<<mostCommonWord(paragraph, banned)<<endl;
    return 0;
}
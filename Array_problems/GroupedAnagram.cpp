
// Problem link - https://leetcode.com/problems/group-anagrams/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // created Map to store grouped anagrams
    unordered_map<string, vector<string>> groupedAnagrams;

    // iterate on each word of string array
    for(string word : strs){
        string sortedWord = word;
        // Sort the characters of the word to use as a key in the hash map
        sort(sortedWord.begin(), sortedWord.end());

        // If the sorted word is already a key, add the word to its corresponding array
        if(groupedAnagrams.find(sortedWord) != groupedAnagrams.end()){
            groupedAnagrams[sortedWord].push_back(word);
        }else{
            // If the key doesn't exist, create a new vector with the word
            vector<string> anagramList = {word};
            // then add the word to its corresponding array
            groupedAnagrams[sortedWord] = anagramList;
        }
    }

    // Print Key Value pair
    for (const auto& pair : groupedAnagrams) {
        cout << "Key: " << pair.first << ", Values: [";
        for (const string& word : pair.second) {
            cout << word << ",";
        }
        cout << "]" << endl;
    }

    // Convert the values of the map to a vector of vectors (grouped anagrams)
    vector<vector<string>> values;
    for(auto pair : groupedAnagrams){
        values.push_back(pair.second);
    }
    return values;
}

int main(){
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    vector<vector<string>> grouped = groupAnagrams(strs);

    // Print the grouped anagrams
    for (const auto& group : grouped) {
        cout << "[";
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
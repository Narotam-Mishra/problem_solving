
// Problem link - https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/?envType=daily-question&envId=2025-10-13

#include<bits/stdc++.h>
using namespace std;

// utility function to check if two strings are Anagram or not
bool areAnagrams(const string& word1, const string& word2){
    if(word1.length() != word2.length()) return false;

    string sortedWord1 = word1;
    string sortedWord2 = word2;

    sort(sortedWord1.begin(), sortedWord1.end());
    sort(sortedWord2.begin(), sortedWord2.end());

    return sortedWord1 == sortedWord2;
}

vector<string> removeAnagrams(vector<string>& words) {
    // step 2 - start from index `1` as need to check previous index (i-1) as well
    int i = 1;

    // step 3 - iterate on words array
    while(i < words.size()){
        // step 4 - check if current word is an anagram of previous word
        if(areAnagrams(words[i], words[i-1])){
            // step 5 - remove current word from `words`
            words.erase(words.begin() + i);

            // step 6 - after removal, step back one position (if possible)
            // the word that was at position i+1 is now at position i
            // we need to check if this "new" word at position i is also an anagram of i-1
            if(i > 1){
                i--;
            }
        }

        // step 7 - otherwise move to next position
        else{
            i++;
        }
    }

    // step 8 - return final list after modification
    return words;
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
    // vector<string> words = {"abba","baba","bbaa","cd","cd"};

    vector<string> words = {"a", "b", "c", "d", "e"};
    vector<string> res = removeAnagrams(words);
    printVector(res);
    return 0;
}
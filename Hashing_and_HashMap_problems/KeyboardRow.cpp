
#include<bits/stdc++.h>
using namespace std;

// step 1: helper function to check if all characters of a word belong to a row
bool isWordInRow(const string& word, const unordered_set<char>& rowSet) {
    for (char ch : word) {
        // convert to lowercase for case-insensitive comparison
        if (!rowSet.count(tolower(ch))) { 
            return false;
        }
    }
    return true;
}

vector<string> findWords(vector<string>& words) {
    // step 2: define sets for each row of keyboard
    unordered_set<char> row1 = {'q','w','e','r','t','y','u','i','o','p'};
    unordered_set<char> row2 = {'a','s','d','f','g','h','j','k','l'};
    unordered_set<char> row3 = {'z','x','c','v','b','n','m'};

    // step 3: store final result in `res`
    vector<string> res; 

    // step 4: loop through each word
    for (const string& word : words) {
        char firstChar = tolower(word[0]);

        // step 5: determine the row for the first character and validate the word
        if (row1.count(firstChar)) {
            if (isWordInRow(word, row1)) res.push_back(word);
        } else if (row2.count(firstChar)) {
            if (isWordInRow(word, row2)) res.push_back(word);
        } else {
            if (isWordInRow(word, row3)) res.push_back(word);
        }
    }

    // step 6 - return res
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
    // vector<string> words = {"Hello","Alaska","Dad","Peace"};

    // vector<string> words = {"omk"};

    vector<string> words = {"adsdf", "sfd"};
    vector<string> res = findWords(words);
    printVector(res);
    return 0;
}
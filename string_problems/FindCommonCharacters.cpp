
#include<bits/stdc++.h>
using namespace std;

vector<string> commonChars(vector<string>& words) {
    // initialize frequency array for first word
    vector<int> commonCount(26, 0);

    // count frequencies in first word
    for (char ch : words[0]) {
        commonCount[ch - 'a']++;
    }

    // iterate through remaining words
    for (int i = 1; i < words.size(); i++) {
        vector<int> currCharCount(26, 0);

        // count frequencies in current word
        for (char ch : words[i]) {
            currCharCount[ch - 'a']++;
        }

        // update common frequencies
        for (int j = 0; j < 26; j++) {
            commonCount[j] = min(commonCount[j], currCharCount[j]);
        }
    }

    // build result 'res' list
    vector<string> res;
    for (int i = 0; i < 26; i++) {
        // add character repeated its common count times
        for (int j = 0; j < commonCount[i]; j++) {
            res.push_back(string(1, 'a' + i));
        }
    }
    // return result 'res' list
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
    // vector<string> words = {"bella","label","roller"};

    vector<string> words = {"cool","lock","cook"};
    vector<string> res = commonChars(words);
    printVector(res);
    return 0;
}
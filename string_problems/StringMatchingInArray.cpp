
#include<bits/stdc++.h>
using namespace std;

vector<string> stringMatching(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
        });

    // store result in res
    unordered_set<string> res;

    // step 2: check each string against longer strings
    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            // check if words[i] is a substring of words[j]
            if (words[j].find(words[i]) != string::npos) {
                // add to the result set 'res'
                res.insert(words[i]);
                break;
            }
        }
    }

    // step 3: convert result set to a list and return
    return vector<string>(res.begin(), res.end());
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
    // vector<string> words = {"mass","as","hero","superhero"};

    // vector<string> words = {"leetcode","et","code"};

    vector<string> words = {"blue","green","bu"};
    vector<string> res = stringMatching(words);
    printVector(res);
    return 0;
}
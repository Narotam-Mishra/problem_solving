
#include<bits/stdc++.h>
using namespace std;

vector<string> findOcurrences(string text, string first, string second) {
    // step 1 - split the text into words
    vector<string> words;
    stringstream ss(text);
    string word;

    while(ss >> word){
        words.push_back(word);
    }

    // step 2 - iterate on each word
    vector<string> res;
    for(int i=0; i<words.size()-2; i++){
        // step 3 - check if current and next word match `first` and `second`
        if(words[i] == first && words[i+1] == second){
            // step 4 - add the third word to result
            res.push_back(words[i+2]);
        }
    }

    // step 5 - return the array of found words in String[]
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
    // string text = "alice is a good girl she is a good student", first = "a", second = "good";

    string text = "we will we will rock you", first = "we", second = "will";
    vector<string> res = findOcurrences(text, first, second);
    printVector(res);
    return 0;
}
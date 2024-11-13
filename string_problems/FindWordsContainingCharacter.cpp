
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

vector<int> findWordsContaining(vector<string>& words, char x) {
    // vector to store indices of matching words
    vector<int> res;

    // iterate through each word in the vector
    for(int i=0; i<words.size(); i++){
        string& currWord = words[i];

        // check if the current word contains the character x
        if(currWord.find(x) != string::npos){
            // if it does, add the index to the result vector
            res.push_back(i);
        }
    }

    // return the vector of indices where words contain the character x
    return res;
}

int main(){
    // vector<string> words = {"leet","code"};
    // char ch = 'e';

    // vector<string> words = {"abc","bcd","aaaa","cbc"};
    // char ch = 'a';

    vector<string> words = {"abc","bcd","aaaa","cbc"};
    char ch = 'z';
    vector<int> res = findWordsContaining(words, ch);
    printVector(res);
    return 0;
}
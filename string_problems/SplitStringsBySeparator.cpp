
// Problem link - https://leetcode.com/problems/split-strings-by-separator/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
    // step 1 - store final result in `res`
    vector<string> res;

    // step 2 - iterate on each word of words
    for (const string& word : words) {
        // step 3 - split the word by given separator
        stringstream ss(word);
        string part;

        // step 4 - filter out empty strings and add to res
        while (getline(ss, part, separator)) {
            if (!part.empty()) {
                res.push_back(part);
            }
        }
    }

    // step 5 - return result array `res`
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
    // vector<string> words = {"one.two.three","four.five","six"};
    // char separator = '.';

    // vector<string> words = {"$easy$","$problem$"};
    // char separator = '$';

    vector<string> words = {"|||"};
    char separator = '|';
    vector<string> res = splitWordsBySeparator(words, separator);
    printVector(res);
    return 0;
}
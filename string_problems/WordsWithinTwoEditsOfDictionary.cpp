
// Problem link - https://leetcode.com/problems/words-within-two-edits-of-dictionary/?envType=daily-question&envId=2026-04-22

#include<bits/stdc++.h>
using namespace std;

vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    // store final result in `res`
    vector<string> res;

    // step 1 - iterate on each query along with word of dictionary
    for(string &query: queries){
        for(string &s : dictionary){
            // keep track of difference
            int diff = 0;

            // step 2 - check each character of query with dictionary word
            for(int i=0; i<query.size(); i++){
                // check for difference in character
                if(s[i] != query[i]){
                    diff++;
                }

                // atmost 2 differences are allowed
                if(diff > 2){
                    break;
                }
            }

            // step 3 - store this query if its character has more than 2 differences
            if(diff <= 2){
                res.push_back(query);
                break;
            }
        }
    }

    // step 4 - return final result, `res`
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
    // vector<string> queries = {"word","note","ants","wood"};
    // vector<string> dictionary = {"wood","joke","moat"};

    vector<string> queries = {"yes"};
    vector<string> dictionary = {"not"};
    vector<string> res = twoEditWords(queries, dictionary);
    printVector(res);
    return 0;
}
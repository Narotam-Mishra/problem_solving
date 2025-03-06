
#include<bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2) {
    // step 1 - use two pointers technique
    int i = 0, j = 0;

    // step 2 - store merged string into `res`
    string res = "";

    // step 3 - iterate on both strings alternatively
    while (i < word1.size() && j < word2.size()) {
        res += word1[i++];
        res += word2[j++];
    }

    // check if some characters are left in word1 
    while (i < word1.size()) {
        res += word1[i++];
    }

    // check if some characters are left in word2 
    while (j < word2.size()) {
        res += word2[j++];
    }

    // step 4 - return final merged string `res`
    return res;
}

int main(){
    // string word1 = "abc", word2 = "pqr";

    // string word1 = "ab", word2 = "pqrs";

    string word1 = "abcd", word2 = "pq";
    cout<<mergeAlternately(word1, word2)<<endl;
    return 0;
}

// Problem link - https://leetcode.com/problems/maximum-product-of-word-lengths/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<string>& words) {
    int n = words.size();
    vector<int> mask(n, 0);
    int maxProd = 0;

    // step1: convert each word to a bit mask
    for(int i=0; i<n; i++){
        // create bit mask for current word
        for(char ch : words[i]){
            // set corresponding bit for each character
            // 'a' is 97 in ASCII, so char.charCodeAt(0) - 97 gives 0-25
            mask[i] |= 1 << (ch - 'a');
        }
    }

    // step2: compare each pair of words using their bit masks
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            // if AND of masks is 0, words have no common letters
            if((mask[i] & mask[j]) == 0){
                // calculate maximum product
                int prod = words[i].size() * words[j].size();
                maxProd = max(maxProd, prod);
            }
        }
    }
    // return maximum product 'maxprod'
    return maxProd;
}

int main(){
    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};

    // vector<string> words = {"a","ab","abc","d","cd","bcd","abcd"};

    // vector<string> words = {"a","aa","aaa","aaaa"};
    cout<<maxProduct(words);
    return 0;
}
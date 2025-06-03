
// Problem link - https://leetcode.com/problems/sort-characters-by-frequency/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    // step 1 - use map to store frequency of each character
    unordered_map<char, int> frqMap;
    for(char ch : s){
        frqMap[ch]++;
    }

    // step 2 - extract characters into vector
    vector<char> chars;
    for(const auto& pair : frqMap){
        chars.push_back(pair.first);
    }

    // step 3 - sort character by its frequency
    sort(chars.begin(), chars.end(), [&frqMap](char a, char b){
        // sorting in desceding order
        return frqMap[b] < frqMap[a];
    });

    // step 4 - build the result
    string res;
    for(char ch : chars){
        res += string(frqMap[ch], ch);
    }

    // step 5 - return resultant string `res`
    return res;
}

int main(){
    // string s = "tree";

    // string s = "cccaaa";

    string s = "Aabb";
    cout<<frequencySort(s)<<endl;
    return 0;
}
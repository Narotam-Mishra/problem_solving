
// Problem link : https://leetcode.com/problems/longest-nice-substring/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

#include <bits/stdc++.h>
using namespace std;

// helper function to check if a substring is "nice"
bool isNiceString(const string& str) {
    // store unique characters
    unordered_set<char> set;  

    // add all characters to the set
    for (char c : str) {
        set.insert(c);
    }

    // check if both uppercase and lowercase versions of each character are present
    for (char c : set) {
        if (set.find(toupper(c)) == set.end() || set.find(tolower(c)) == set.end()) {
            // not nice if either case is missing
            return false;  
        }
    }

    return true; 
}

string longestNiceSubstring(const string& s) {
    int maxLength = 0;  // Track the length of the longest "nice" substring
    string result = ""; // Store the longest "nice" substring

    // iterate over all possible substrings
    for (int i = 0; i < s.length(); i++) {
        for (int j = i + 1; j <= s.length(); j++) {

            // extract substring from index i to j-1
            string substr = s.substr(i, j - i); 

            // check if the current substring is "nice"
            if (isNiceString(substr) && substr.length() > maxLength) {
                // update maxLength
                maxLength = substr.length();

                // store the longest "nice" substring
                result = substr;            
            }
        }
    }

    // return the longest "nice" substring found
    return result;
}

int main() {
    // string input = "YazaAay";

    string input = "Bb";
    cout<<longestNiceSubstring(input)<<endl;
    return 0;
}

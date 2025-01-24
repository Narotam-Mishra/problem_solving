
#include<bits/stdc++.h>
using namespace std;

string decodeMessage(string key, string message) {
    // step 1 - build the substitution map
    unordered_map<char, char> substitutionMap;
    // start with char 'a'
    char alphabet = 'a';

    // iterate through the key to extract unique letters
    for (char ch : key) {
        // skip space and already mapped characters
        if (ch != ' ' && substitutionMap.find(ch) == substitutionMap.end()) {
            substitutionMap[ch] = alphabet;
            alphabet++;

            // stop if all 26 letters have been mapped
            if (alphabet > 'z') break;
        }
    }

    // step 2 - decode the message
    string decodedMessage;
    for (char ch : message) {
        if (ch == ' ') {
            // space remain unchnaged
            decodedMessage += " ";
        }
        else {
            // substitute using map
            decodedMessage += substitutionMap[ch];
        }
    }

    // step 3 - return decoded message
    return decodedMessage;
}

int main(){
    // string key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";
    
    string key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv";
    cout<<decodeMessage(key, message)<<endl;
    return 0;
}
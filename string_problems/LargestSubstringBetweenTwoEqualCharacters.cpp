
#include<bits/stdc++.h>
using namespace std;

int maxLengthBetweenEqualCharacters(string s) {
    // step 1 - initialize a map to store the first occurrence of each character
    unordered_map<char, int> map;

    // step 2 - variable to store the maximum length of substring found
    int maxLength = -1;

    // step 3 - iterate through the string and find largest sbstring length
    for(int i=0; i<s.length(); i++){
        char currChar = s[i];

        // check if the current character has been seen before
        if(map.find(currChar) != map.end()){
            // calculate the length of the largest substring between the two occurrences
            int lengthBetween = i - map[currChar] - 1;

            // update the maximum substring length
            maxLength = max(maxLength, lengthBetween);
        }else{
            // store the first occurrence index of the character
            map[currChar] = i;
        }
    }

    // step 4 - return the maximum length found, or -1 if no such substring exists
    return maxLength;
}

int main(){
    // string str = "aa";

    // string str = "abca";

    string str = "cbzxy";
    cout<<maxLengthBetweenEqualCharacters(str)<<endl;
    return 0;
}
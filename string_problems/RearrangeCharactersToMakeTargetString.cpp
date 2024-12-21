
#include<bits/stdc++.h>
using namespace std;

// helper function to create a frequency array of characters in a string
vector<int> createFrequencyArray(string s){
    vector<int> freq(26, 0);
    for(char c: s){
        freq[c-'a']++;
    }
    return freq;
}

int rearrangeCharacters(string s, string target) {
    // step 1 - create frequency arrays for both s and target
    vector<int> strMap = createFrequencyArray(s);
    vector<int> targetMap = createFrequencyArray(target);

    // step 2 - initialize the maximum number of copies to a large number
    int maxCopies = INT_MAX;
    
    // step 3 - calculate the maximum number of copies of target that can be formed
    for(int i=0; i<26; i++){
        if(targetMap[i] > 0){
            if(strMap[i] == 0){
                // if a character in target is not present in s, we can't form target even once
                return 0;
            }

            // calculate how many times this character can contribute to forming target
            int possibleCopies = strMap[i] / targetMap[i];
            
            // update the maximum number of copies
            maxCopies = min(maxCopies, possibleCopies);
        }
    }

    // step 4 - return `maxCopies` maximum copies possible
    return maxCopies;
}
int main(){
    // string s = "ilovecodingonleetcode", target = "code";
    
    string s = "abbaccaddaeea", target = "aaaaa";
    cout<<rearrangeCharacters(s, target)<<endl;
    return 0;
}
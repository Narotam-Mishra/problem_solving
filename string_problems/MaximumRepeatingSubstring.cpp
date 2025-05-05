
// Problem link - https://leetcode.com/problems/maximum-repeating-substring/description/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int maxRepeating(string sequence, string word) {
    // step 1 - maximum number of times word can repeat within sequence
    int k = 1;
    string repeated = word;

    // step 2 - keep repeating the word and check if it's in sequence
    while (sequence.find(repeated) != string::npos) {
        k++;
        repeated += word;  // Append word one more time
    }

    // step 3 - last valid k was one less, so return k-1
    return k - 1;
}

int main(){
    // string sequence = "ababc", word = "ab";

    // string sequence = "ababc", word = "ba";

    string sequence = "ababc", word = "ac";
    cout<<maxRepeating(sequence, word)<<endl;
    return 0;
}
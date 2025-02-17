
#include<bits/stdc++.h>
using namespace std;

string findValidPair(string s) {
    // step 1 - create a frequency map using fixed size array 
    // to count the occurrences of each digit in the string
    vector<int>freq(10, 0);

    // step 2 - populate the frequency array map
    for (char ch : s) {
        freq[ch - '0']++;
    }

    // step 3 - traverse the string to check for the first valid pair
    for (int i = 0; i < s.size() - 1; i++) {
        int firstDigit = s[i] - '0';
        int secondDigit = s[i + 1] - '0';

        // a valid pair requires the two digits to be different
        if (firstDigit != secondDigit) {
            // check if the frequency of each digit matches its numeric value
            if (freq[firstDigit] == firstDigit && freq[secondDigit] == secondDigit) {
                return s.substr(i, 2);
            }
        }
    }

    // step 4 - if no valid pair is found, return an empty string
    return "";
}

int main(){
    // string s = "2523533";

    // string s = "221";

    string s = "22";
    cout<<findValidPair(s)<<endl;
    return 0;
}
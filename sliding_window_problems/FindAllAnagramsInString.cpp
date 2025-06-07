
// Problem link - https://leetcode.com/problems/find-all-anagrams-in-a-string/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    // step 1 - store result in `res` list
    vector<int> res;

    // check for base case:
    if (p.size() > s.size()) {
        return res;
    }

    // step 2 - using fixed size frequency arrays to count frquencies
    vector<int> pCount(26, 0);
    vector<int> windowCount(26, 0);

    // step 3 - count pattern frquencies
    for (char ch : p) {
        pCount[ch - 'a']++;
    }

    // step 4 - calculate window size
    int windowSize = p.length();

    // step 5 - initialize first window
    for (int i = 0; i < windowSize; i++) {
        windowCount[s[i] - 'a']++;
    }

    // step 6 - check first window
    if (pCount == windowCount) {
        res.push_back(0);
    }

    // step 7 - slide through each the window
    for (int i = windowSize; i < s.length(); i++) {
        // add character's frequency to window
        windowCount[s[i] - 'a']++;

        // remove character's frequency from window
        windowCount[s[i - windowSize] - 'a']--;

        // check current window
        if (pCount == windowCount) {
            res.push_back(i - windowSize + 1);
        }
    }

    // step 8 - return resultant list `res`
    return res;
}

void printVector(vector<int>& vec){
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
    // string s = "cbaebabacd", p = "abc";

    string s = "abab", p = "ab";
    vector<int> res = findAnagrams(s, p);
    printVector(res);
    return 0;
}
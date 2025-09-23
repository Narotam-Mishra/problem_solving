
// Problem link - https://leetcode.com/problems/compare-version-numbers/description/?envType=daily-question&envId=2025-09-23

#include<bits/stdc++.h>
using namespace std;

// utility function for split()
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int compareVersion(string version1, string version2) {
    // step 1 - split both versions of input strings by dot
    vector<string> rev1 = split(version1, '.');
    vector<string> rev2 = split(version2, '.');

    // step 2 - find maximum length of input strings
    int maxLen = max(rev1.size(), rev2.size());

    // step 3 - find maximum length of input strings
    for (int i = 0; i < maxLen; i++) {
        // step 4 - get revision at current position, defaulting to "0" if missing
        string strRev1 = (i < rev1.size()) ? rev1[i] : "0";
        string strRev2 = (i < rev2.size()) ? rev2[i] : "0";

        // step 5 - convert string revision to number for easy comparison
        int num1 = stoi(strRev1);
        int num2 = stoi(strRev2);

        // step 6 - compare the current revision numbers
        if (num1 < num2) {
            // case 1 - return -1
            return -1;
        }
        else if (num1 > num2) {
            // case 2 - return 1
            return 1;
        }
    }

    // step 7 - all revisions are equal, so return 0
    return 0;
}

int main(){
    string version1 = "1.2", version2 = "1.10";
    cout<<compareVersion(version1, version2);
    return 0;
}
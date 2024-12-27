
#include<bits/stdc++.h>
using namespace std;

bool areAlmostEqual(string s1, string s2) {
    // step 1 - if the strings are already equal, return true
    if(s1 == s2) return true;

    // step 2 - find mismatched indices
    vector<int> mismatches;
    for(int i=0; i<s1.size(); i++){
        if(s1[i] != s2[i]){
            mismatches.push_back(i);

            // if more than 2 mismatches, return false
            if(mismatches.size() > 2) return false;
        }
    }

    // step 3 - check if exactly two mismatches can be fixed by a swap
    if(mismatches.size() == 2){
        int i = mismatches[0], j = mismatches[1];
        return (s1[i] == s2[j] && s1[j] == s2[i]);
    }

    // step 4 - if mismatch count is not 2, return false
    return false;
}

int main(){
    // string s1 = "bank", s2 = "kanb";

    // string s1 = "attack", s2 = "defend";

    string s1 = "kelb", s2 = "kelb";
    bool res = areAlmostEqual(s1, s2);
    res ? cout<<"true" : cout<<"false"<<endl;
    return 0;
}
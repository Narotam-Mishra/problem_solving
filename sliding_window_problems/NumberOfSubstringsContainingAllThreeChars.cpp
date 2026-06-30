
// Problem link - https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/?envType=daily-question&envId=2026-06-30

#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    // fins size of sstring, `s`
    int n = s.size();

    // keep track of number of valid substrings 
    int res = 0;

    // step 1 - count valid substrings in current window
    vector<int> frq(3, 0);
    int l = 0;
    for(int r=0; r<n; r++){
        // include s[r] in the current window
        frq[s[r] - 'a']++;

        // step 2 - shrink from left while the window contains all three characters
        while(frq[0]>0 && frq[1]>0 && frq[2]>0){
            frq[s[l] - 'a']--;
            l++;
        }

        // now [l-1, r] was the largest valid window ending at 'r'
        // step 3 - all starts from 0 to left-1 are valid
        res += l;
    }

    // step 4 - return final result, `res`
    return res;
}

int main(){
    // string s = "abcabc";

    // string s = "aaabc";

    string s = "abc";
    cout<<numberOfSubstrings(s);
    return 0;
}
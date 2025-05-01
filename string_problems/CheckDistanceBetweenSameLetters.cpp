
// Problem link - https://leetcode.com/problems/check-distances-between-same-letters/description/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

bool checkDistances(string s, vector<int>& distance) {
    // step 1 - array to store the index of first occurrence of each character
    vector<int> firstIndexArr(26, -1);

    // step 2 - iterate on each character of `s`
    for(int i=0; i<s.size(); i++){
        // convert each character to corresponding number
        // 'a' --> 0, 'b' --> 1, .... 'z' --> 25
        int charCode = s[i] - 'a';

        // step 3 - if first time seeing this character then store its index
        if(firstIndexArr[charCode] == -1){
            firstIndexArr[charCode] = i;
        }else{
            // step 4 - if second time seeing this, calculate the distance
            int actualDistance = i - firstIndexArr[charCode] - 1;

            // step 5 - check actual distance with distance array
            if(actualDistance != distance[charCode]){
                return false;
            }
        }
    }

    // step 6 - all character matched the required distance, return true
    return true;
}

int main(){
    // string s = "abaccb";
    // vector<int> distance = {1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    string s = "aa";
    vector<int> distance = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    bool res = checkDistances(s, distance);
    res ? cout<<"true" : cout<<"false";
    return 0;
}
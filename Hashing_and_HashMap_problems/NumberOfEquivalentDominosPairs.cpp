
#include<bits/stdc++.h>
using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    // step 1: normalize each domino by sorting the pair
    map<pair<int, int>, int> normalized;

    for (const auto& domino : dominoes) {
        int a = domino[0];
        int b = domino[1];

        // normalize the domino
        pair<int, int> key = {min(a, b), max(a, b)}; 

        // set the key pair count in map
        normalized[key]++;
    }

    // step 2: calculate the number of pairs
    int pairs = 0;
    for (const auto& [key, count] : normalized) {
        if (count >= 2) {
            // calculate the number of pairs using the combination formula C(n, 2) = n * (n - 1) / 2
            pairs += (count * (count - 1)) / 2;
        }
    }

    // step 3 - return number of valid pairs
    return pairs;
}

int main(){
    // vector<vector<int>> dominoes = {{1,2},{2,1},{3,4},{5,6}};

    vector<vector<int>> dominoes = {{1,2},{1,2},{1,1},{1,2},{2,2}};
    cout<<numEquivDominoPairs(dominoes)<<endl;
    return 0;
}
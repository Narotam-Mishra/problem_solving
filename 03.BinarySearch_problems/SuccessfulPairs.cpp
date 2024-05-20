
// Problem link - https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

#include<bits/stdc++.h>
using namespace std;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    int n = spells.size(), m = potions.size();

    // create vector of pair to store the spells[i] element and index i
    vector<pair<int,int>> spellPairs(n);
    for(int i=0; i<n; i++){
        spellPairs[i] = {spells[i], i};
    }

    // sort spellPairs by spell's element (i.e strength)
    sort(spellPairs.begin(), spellPairs.end());

    // sort potions array in descending order
    sort(potions.begin(), potions.end(), greater<int>());

    // array to store success pair count
    vector<int> sucessPairs(n);

    // For each spell of spells, count successful pairs for each spell
    for(int i=0, j=0; i<n; ++i){
        while (j < m && static_cast<long long>(potions[j]) * spellPairs[i].first >= success){
            ++j;
        }
        // update the count of successful pairs at the original spell index
        sucessPairs[spellPairs[i].second] = j;
    }
    // Return array with counts of successful pairs for each spell in original order
    return sucessPairs;
}

int main(){
    // vector<int> spells = {5, 1, 3};
    // vector<int> potions = {1, 2, 3, 4, 5};
    // long long success = 7;

    vector<int> spells = {3,1,2};
    vector<int> potions = {8,5,8};
    long long success = 16;

    vector<int> ans = successfulPairs(spells, potions, success);
    for(int num : ans){
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}
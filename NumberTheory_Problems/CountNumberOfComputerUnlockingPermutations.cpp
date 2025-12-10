
// Problem link - https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/description/?envType=daily-question&envId=2025-12-10

#include<bits/stdc++.h>
using namespace std;

int countPermutations(vector<int>& complexity) {
    const int mod = 1e9 + 7;

    // initialized result, `res` to 1
    // as first computer is already unlocked
    long long res = 1;
    
    // step 1 - iterate on each complexity
    // we start from index 1 as computer0 (index - 0) is already unlocked
    int n = complexity.size();
    for(int i=1; i<n; i++){
        // step 2 - check if complexity[i] <= complexity[0], no earlier unlocked computer has
        // lower complexity => unlocking i is impossible => return 0.
        if(complexity[i] <= complexity[0]){
            return 0;
        }

        // step 3 - for every valid i, we can place it in ANY of the i available
        // positions among the already placed computers.
        res = (res * i) % mod;
    }

    // step 4 - return final result, `res`
    return (int)res;
}

int main(){
    // vector<int> complexity = {1,2,3};

    vector<int> complexity = {3,3,3,4,4,4};
    cout<<countPermutations(complexity);
    return 0;
}
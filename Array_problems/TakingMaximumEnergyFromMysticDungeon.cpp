
// Problem link - https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/?envType=daily-question&envId=2025-10-10

#include<bits/stdc++.h>
using namespace std;

int maximumEnergy(vector<int>& energy, int k) {
    // get size of energy list
    int n = energy.size();

    // assume maximum energy is minimum value initially
    int maxEnergy = INT_MIN;

    // step 1 - iterate backwards from the last magician to the first
    // this allows us to build optimal paths by reusing previously calculated results
    for (int i = n - 1; i >= 0; i--) {
        // step 2 - if there's a next magician at position (i + k), add their accumulated energy
        if (i + k < n) {
            energy[i] += energy[i + k];
        }

        // if (i + k >= n), magician at 'i' is already at the end of a path chain
        // So energy[i] remains as is (the final stop)

        // step 3 - update maximum energy so far
        // energy[i] now contains the total energy from starting at position 'i'
        maxEnergy = max(maxEnergy, energy[i]);
    }

    // step 4 - return maximum energy
    return maxEnergy;
}

int main(){
    // vector<int> energy = {5,2,-10,-5,1};
    // int k = 3;

    vector<int> energy = {-2,-3,-1};
    int k = 2;
    cout<<maximumEnergy(energy, k);
    return 0;
}
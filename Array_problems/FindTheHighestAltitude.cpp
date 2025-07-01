
// problem link - https://leetcode.com/problems/find-the-highest-altitude/description/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int>& gain) {
    // store mhighest altitude in `maxAltitude`
    int maxAltitude = 0;

    // step 1 - process each gain/loss in altitude
    int currAltitude = 0;
    for (int num : gain) {
        // step 2 - // update current altitude by adding the gain
        currAltitude += num;

        // step 3 - check if this is the highest altitude we've seen so far
        if (currAltitude > maxAltitude) {
            // update maxAltitude if current altitude is higher
            maxAltitude = currAltitude;
        }
    }

    // step 4 - return the highest altitude `maxAltitude` encountered during the
    // trip
    return maxAltitude;
}

int main(){
    // vector<int> gain = {-5,1,5,0,-7};

    vector<int> gain = {-4,-3,-2,-1,4,3,2};
    cout<<largestAltitude(gain)<<endl;
    return 0;
}
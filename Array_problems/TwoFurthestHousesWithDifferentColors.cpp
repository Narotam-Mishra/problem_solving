
// Problem link - https://leetcode.com/problems/two-furthest-houses-with-different-colors/?envType=daily-question&envId=2026-04-20

#include<bits/stdc++.h>
using namespace std;

int maxDistance1(vector<int>& colors) {
    int n = colors.size();

    // using two-pointers approach
    int i=0, j=n-1;

    // step 1 - iterate input array from forward
    int maxDis = 0;
    while(colors[i] == colors[j]){
        // keep moving forward pointers if it is same as backward
        i++;
    }

    // step 2 - find and updated maximum distance
    maxDis = max(maxDis, abs(j-i));

    // step 3 - iterate array from backward
    while(colors[0] == colors[j]){
        // keep moving backward pointers if it is same as forward
        j--;
    }

    // step 4 - find and updated maximum distance
    maxDis = max(maxDis, j);

    // step 5 - return maximum distance
    return maxDis;
}

int maxDistance(vector<int>& colors) {
    // find size of `colors`
    int n = colors.size();

    // keep track of maximum distance
    int maxDis = 0;

    // step 1 - iterate on colors 
    for(int i=0; i<n; i++){
        // step 2 - find and updated maximum distance from forward side
        if(colors[i] != colors[0]){
            maxDis = max(maxDis, i);
        }

        // step 3 - find and updated maximum distance from backward side
        if(colors[i] != colors[n-1]){
            maxDis = max(maxDis, abs(i-(n-1)));
        }
    }

    // step 4 - return maximum distance
    return maxDis;
}

int main(){
    // vector<int> colors = {1,1,1,6,1,1,1};

    // vector<int> colors = {1,8,3,8,3};

    // vector<int> colors = {0,1};

    vector<int> colors = {6,6,6,6,6,6,6,6,6,19,19,6,6};
    cout<<maxDistance(colors);
}
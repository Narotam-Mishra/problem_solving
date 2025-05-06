
// Problem link - https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int closestTarget(vector<string>& words, string target, int startIndex) {
    // step 1 - initialize variable to find minimum distance `minDistance`
    int minDistance = INT_MAX;
    int n = words.size();

    // step 2 - iterate on each word of `words` array
    for (int i = 0; i < n; i++) {
        // if target is found
        if (words[i] == target) {
            // step 3 - calculate forward distance
            int forwardDistance = (i - startIndex + n) % n;

            // step 4 - calculate backward distance
            int backwardDistance = (startIndex - i + n) % n;

            // step 5 - find minimum distance from forward and backward distance
            int distance = min(forwardDistance, backwardDistance);

            // update minimum distance
            minDistance = min(distance, minDistance);
        }
    }

    // step 6 - return minimum distance
    return minDistance == INT_MAX ? -1 : minDistance;
}

int main(){
    // vector<string> words = {"hello","i","am","leetcode","hello"};
    // string target = "hello";
    // int startIndex = 1;

    // vector<string> words = {"a","b","leetcode"};
    // string target = "leetcode";
    // int startIndex = 0;

    vector<string> words = {"i","eat","leetcode"};
    string target = "ate";
    int startIndex = -1;
    cout<<closestTarget(words, target, startIndex)<<endl;
    return 0;
}
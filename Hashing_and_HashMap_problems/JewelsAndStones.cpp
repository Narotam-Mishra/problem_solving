
#include<bits/stdc++.h>
using namespace std;

int numJewelsInStones(string jewels, string stones) {
    // initialize a counter to track the number of jewels in stones.
    int count = 0;

    // loop through each character in stones.
    for (char stone : stones) {
        // check if the current stone is in the jewel.
        if (jewels.find(stone) != string::npos) {
            // increment the count if it is a jewel
            count++;
        }
    }

    // return the total count of jewels in stones.
    return count;
}

int main(){
    // string jewels = "aA", stones = "aAAbbbb";

    string jewels = "z", stones = "ZZ";
    cout<<numJewelsInStones(jewels, stones)<<endl;
    return 0;
}
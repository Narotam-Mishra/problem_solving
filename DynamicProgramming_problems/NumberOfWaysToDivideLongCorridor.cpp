
// Problem link - https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/?envType=daily-question&envId=2025-12-14

#include<bits/stdc++.h>
using namespace std;

int numberOfWays(string corridor) {
    const int mod = 1e9 + 7;
    
    // step 1 - store indices of all seats, `S`
    int n = corridor.size();
    vector<int> seatIndices;
    for (int i = 0; i < n; i++) {
        if (corridor[i] == 'S') {
            seatIndices.push_back(i);
        }
    }

    // edge case - if number of seats is 0 or odd, return 0
    if(seatIndices.size() % 2 != 0 || seatIndices.size() == 0){
        return 0;
    }

    // step 2 - find previous and next seat indices for each pair of seats and find number of ways
    long long res = 1;
    int prevSeatIndex = seatIndices[1];
    for (int i = 2; i < seatIndices.size(); i+=2) {
        // find partition size
        int paritionSize = seatIndices[i] - prevSeatIndex;
        
        // update result
        res = (res * paritionSize) % mod;

        // update `prevSeatIndex`
        prevSeatIndex = seatIndices[i + 1];
    }
    
    // step 3 - return final result, `res`
    return (int)res;
}

int main(){
    // string corridor = "SSPPSPS";

    // string corridor = "PPSPSP";

    string corridor = "S";
    cout << numberOfWays(corridor) << endl;
    return 0;
}
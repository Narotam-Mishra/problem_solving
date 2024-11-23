
#include<bits/stdc++.h>
using namespace std;

// helper function to calculate the greatest common divisor (GCD) using Euclid's algorithm
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool hasGroupsSizeX(vector<int>& deck) {
    // step 1: create a frequency map to store frequency of each number
    unordered_map<int, int> frqMap;
    for(int cardNum : deck){
        frqMap[cardNum]++;
    }

    // step 2: extract frequency values
    vector<int> counts;
    for(const auto& pair : frqMap){
        counts.push_back(pair.second);
    }

    // step 3: compute GCD for all frequency counts
    int overallGCD = counts[0];
    for (int i = 1; i < counts.size(); i++) {
        overallGCD = findGCD(overallGCD, counts[i]);

        // early exit: if at any point GCD becomes 1, no valid grouping is possible
        if (overallGCD == 1) return false;
    }

    // step 4: return true if GCD >= 2
    return overallGCD >= 2;
}

int main(){
    // vector<int> deck = {1,2,3,4,4,3,2,1};

    vector<int> deck = {1,1,1,2,2,2,3,3};
    bool res = hasGroupsSizeX(deck);
    res ? cout<<"true" : cout<<"false";
    return 0;
}
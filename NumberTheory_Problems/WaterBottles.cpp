
// Problem link - https://leetcode.com/problems/water-bottles/?envType=daily-question&envId=2025-10-01

#include<bits/stdc++.h>
using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    // step 1 - start drinking all initial bottels
    int totalDrink = numBottles;

    // step 2 - now we have `numBottles` empty bottles to work with
    int emptyBottles = numBottles;

    // step 3 - keep exchanging while we have enough empty bottles
    while(emptyBottles >= numExchange){
        // step 4 - exchange : get new full bottles
        int newBottles = emptyBottles / numExchange;

        // step 5 - drink the new bottles immediately
        totalDrink += newBottles;

        // step 6 - update empty bottles: leftover + newly drunk bottles
        emptyBottles = emptyBottles % numExchange + newBottles;
    }

    // step 7 - return the maximum number of water bottles we can drink
    return totalDrink;
}

int main(){
    // int numBottles = 9, numExchange = 3;

    int numBottles = 15, numExchange = 4;
    cout<<numWaterBottles(numBottles, numExchange);
    return 0;
}
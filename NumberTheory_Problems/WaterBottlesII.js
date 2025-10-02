
// Problem link - https://leetcode.com/problems/water-bottles-ii/description/?envType=daily-question&envId=2025-10-02

let maxBottlesDrunk = function(numBottles, numExchange) {
    // step 1 - start with drinking all initial bottles
    let totalDrink = numBottles;

    // step 2 - now we have `numBottles` empty bottles to work with
    let emptyBottles = numBottles;

    //step 3 - keep exchanging while we have enough empty bottles
    while(emptyBottles >= numExchange){
        // step 4 - exchange empty bottles for 1 full bottle
        emptyBottles -= numExchange;

        // step 5 - drink new full bottle
        totalDrink += 1;

        // step 6 - now one full bottle become empty
        emptyBottles += 1

        // step 7 - increase exchnage rate
        numExchange += 1;
    }

    // step 8 - return the maximum number of water bottles we can drink
    return totalDrink;
};
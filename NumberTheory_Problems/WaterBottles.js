
// Problem link - https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2025-10-01

let numWaterBottles = function(numBottles, numExchange) {
    // step 1 - start with drinking all initial bottles
    let totalDrink = numBottles;

    // step 2 - now we have numBottles empty bottles to work with
    let emptyBottles = numBottles;

    //step 3 - keep exchanging while we have enough empty bottles
    while(emptyBottles >= numExchange){
        // step 4 - exchange: get new full bottles
        let newBottles = Math.floor(emptyBottles / numExchange);

        // step 5 - drink the new bottles immediately
        totalDrink += newBottles;

        // step 6 - update empty bottles: leftover + newly drunk bottles
        emptyBottles = emptyBottles % numExchange + newBottles;
    }

    // step 7 - return the maximum number of water bottles we can drink
    return totalDrink;
};

const numBottles = 9, numExchange = 3;

// const numBottles = 15, numExchange = 4;
console.log(numWaterBottles(numBottles, numExchange));
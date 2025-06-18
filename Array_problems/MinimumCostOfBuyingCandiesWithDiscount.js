
// Problem link - https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/

// using Greedy Approach
let minimumCost1 = function(cost) {
    // store minimum cost of all candies in `minCost`
    let minCost = 0;

    // step 1 - sort the candies in desending order to get most expensive first
    // this ensures we buy the most expensive candies and get cheaper ones free
    cost.sort((a,b) => b-a);

    // step 2 - process candies in groups of 3
    // for every 3 candies: buy 2 most expensive, get 1 cheapest free
    for(let i=0; i<cost.length; i++){

        // step 3 - check if this candy needs to be paid for
        // we get free candies at positions: 2, 5, 8, 11, ... (every 3rd candy)
        if(i % 3 !== 2){
            // this is not the 3rd candy in a group, so we need to pay for it
            minCost += cost[i];
        }
    }

    // step 4 - return minimum cost of all candies in `minCost`
    return minCost;
};

let minimumCost = function(cost) {
    // store minimum cost of all candies in `minCost`
    let minCost = 0;

    // step 1 - sort the candies in desending order to get most expensive first
    // this ensures we buy the most expensive candies and get cheaper ones free
    cost.sort((a,b) => b-a);

    // step 2 - process candies in groups of 3
    // for every 3 candies: buy 2 most expensive, get 1 cheapest free
    for(let i=0; i<cost.length; i+=3){

        // step 3 - buy the first candy in the group (most expensive)
        minCost += cost[i]

        // step 4 - buy the second candy in the group if it exists
        if (i + 1 < cost.length) {
            minCost += cost[i + 1];
        }
    }

    // step 5 - return minimum cost of all candies in `minCost`
    return minCost;
};

const cost = [1,2,3];

// const cost = [6,5,7,9,2,2];

// const cost = [5,5];
console.log(minimumCost(cost));
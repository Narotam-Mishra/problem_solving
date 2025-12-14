
// Problem link - https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/?envType=daily-question&envId=2025-12-14

let numberOfWays = function(corridor) {
    // step 1 - find all the seats positions
    let seatsPositions = [];
    for (let i = 0; i < corridor.length; i++) {
        if (corridor[i] === 'S') {
            seatsPositions.push(i);
        }
    }

    // step 2 - if number of seats is odd, return 0
    if (seatsPositions.length % 2 !== 0 || seatsPositions.length === 0) {
        return 0;
    }

    // step 3 - calculate the number of ways to divide the corridor
    let ways = 1;
    let previousSeatIndex = seatsPositions[1];
    const mod = 1e9 + 7;
    for (let i = 2; i < seatsPositions.length; i += 2){
        // find partitions between pairs of seats
        let partitionSize = seatsPositions[i] - previousSeatIndex;
        
        // multiply the ways with partition size
        ways = (ways * partitionSize) % mod;

        // update previous seat index
        previousSeatIndex = seatsPositions[i + 1];
    }

    // step 4 - return the total ways
    return ways;
};

// const corridor = "SSPPSPS"

// const corridor = "PPSPSP";

const corridor = "S";
console.log(numberOfWays(corridor));
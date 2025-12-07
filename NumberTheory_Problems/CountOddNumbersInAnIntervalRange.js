
// Problem link - https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/?envType=daily-question&envId=2025-12-07

let countOdds = function (low, high) {
    // step 1 - calculate total number in range
    let totalNums = high - low + 1;

    // step 2 - check if low is odd, we need ceiling of (totalNumbers / 2)
    // if low is even, we need floor of (totalNumbers / 2)
    if (low % 2 == 1) {
        return Math.floor((totalNums + 1) / 2);
    } else {
        return Math.floor(totalNums / 2);
    }
};

// const low = 3, high = 7;

const low = 8, high = 10;
console.log(countOdds(low, high));
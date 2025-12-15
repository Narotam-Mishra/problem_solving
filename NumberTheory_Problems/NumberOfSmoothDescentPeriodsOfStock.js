
// Problem link - https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/?envType=daily-question&envId=2025-12-15

let getDescentPeriods = function (prices) {
    // get size of `prices`
    let n = prices.length;

    // step 1 - iterate on each prices
    let count = 1, res = 1;
    for (let i = 1; i < n; i++) {
        // step 2 - check if current price and previous price is differ by 1 or not
        if (prices[i - 1] - prices[i] == 1) {
            // increment count
            count++;
        } else {
            // otherwise reset count to 1
            count = 1;
        }

        // step 3 - add count leto result, `res`
        res += count;
    }

    // step 4 - return final result, `res`
    return res;
};

const prices = [3, 2, 1, 4];
console.log(getDescentPeriods(prices)); // Output: 7
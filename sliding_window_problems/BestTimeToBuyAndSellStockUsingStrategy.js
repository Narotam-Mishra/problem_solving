
// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/description/

let maxProfit = function (prices, strategy, k) {
    // step 1 - find profit for each stock price and strategy
    let n = prices.length;
    const profit = new Array(n).fill(0);
    let actualProfit = 0;
    for (let i = 0; i < n; i++) {
        profit[i] = prices[i] * strategy[i];
        actualProfit += profit[i];
    }

    // keep track of maximum original window profit
    let originalWindowProfit = 0;

    // keep track of maximum modified window profit
    let modifiedWindowProfit = 0;

    // keep track of maximum profit for each window
    let maxGain = 0;

    // using sliding window approach
    let i = 0,
        j = 0;
    while (j < n) {
        originalWindowProfit += profit[j];

        // step 2 - find modified window profit using second half of window
        if (j - i + 1 > k / 2) {
            modifiedWindowProfit += prices[j];
        }

        // check if window size exceed `k`
        if (j - i + 1 > k) {
            // shrink window
            originalWindowProfit -= profit[i];
            modifiedWindowProfit -= prices[i + k / 2];
            i++;
        }

        // step 3 - find maximum profit in window of size `k`
        if (j - i + 1 == k) {
            maxGain = Math.max(maxGain, modifiedWindowProfit - originalWindowProfit);
        }

        // move to next window
        j++;
    }

    // step 4 - return maximum profit
    return actualProfit + maxGain;
};

// const prices = [4,2,8], strategy = [-1,0,1], k = 2;

const prices = [5,4,3], strategy = [1,1,0], k = 2;
console.log(maxProfit(prices, strategy, k));

// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

let maxProfit = function(prices) {
    let curMin = prices[0];
    let maxProfit = 0;

    for(let i=1; i<prices.length; i++) {
        // can I buy stock?
        if(prices[i] < curMin) {
            curMin = prices[i];
        }
        // can I sell stock?, check for maximum profit
        if(prices[i] > curMin){
            maxProfit = Math.max(maxProfit, prices[i] - curMin);
        }
    }
    return maxProfit;
};


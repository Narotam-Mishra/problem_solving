
// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

// Approach - Using Recursion

let pArr;

function findMaxProfitRec(i, ts, k){
    // Base case: all days are completed
    if(i === pArr.length) return 0;

    let ans = Number.MIN_VALUE;

    // Recursive case:
    // Case 1 : Ignore stock
    ans = Math.max(ans, findMaxProfitRec(i+1, ts, k));

    // Case 2 : Buy the stock on ith day
    if(k > 0 && ts === false){
        ans = Math.max(ans, -pArr[i] + findMaxProfitRec(i+1, true, k));
    }

    // Case 3 : sell the stock on the i-th day
    if(ts === true){
        ans = Math.max(ans, pArr[i] + findMaxProfitRec(i+1, false, k-1));
    }
    return ans;
}

let maxProfit = function(k, prices) {
    pArr = prices;
    return findMaxProfitRec(0, false, k);
};

let k = 2;
// let prices = [2,4,1];

let prices = [3,2,6,5,0,3]
console.log(maxProfit(k, prices));
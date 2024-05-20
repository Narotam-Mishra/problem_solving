
// Problem link - https://leetcode.com/problems/minimum-cost-for-tickets/description/

// Approach - using Bottom Up DP

// global variables 'dArr' for days & 'cArr' for costs array
let dArr;
let cArr;

// using to set store days
let s;

let dp;
let lastDay;

function findMinimumCostBottomUpDP(){
    dp = Array(400).fill(0);

    for (let day = 365; day >= 1; day--) {
      // base case1: if 'd'th day is greater than last day of days array
      if (day > lastDay) dp[day] = 0;
      // if dth day doesn't exist in set
      else if (!s.has(day)) dp[day] = dp[day + 1];

      else{
        let ans = Math.min(
            cArr[0] + dp[day + 1],
            cArr[1] + dp[day + 7],
            cArr[2] + dp[day + 30]
          );
        dp[day] = ans;
      }
    }
    return dp[1];
}

let mincostTickets = function(days, costs) {
    s = new Set(days);
    dArr = days;
    lastDay = dArr[dArr.length - 1];
    cArr = costs;
    return findMinimumCostBottomUpDP();
};

// let days = [1,4,6,7,8,20];
// let costs = [2,7,15];

// let days = [1,2,3,4,5,6,7,8,9,10,30,31];
// let costs = [2,7,15];

let days = [1,4,6,7,8,365];
let costs = [2,7,15];

let ans = mincostTickets(days, costs);
console.log(ans);
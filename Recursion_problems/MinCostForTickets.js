
// Problem link - https://leetcode.com/problems/minimum-cost-for-tickets/description/


// Approach - using Recursion

// global variables 'dArr' for days & 'cArr' for costs array
let dArr;
let cArr;

// using to set store days
let s;

function findMinimumCostRec(d){
    // base case1: if 'd'th day is greater than last day of days array
    if(d > dArr[dArr.length - 1]) return 0;
    // Recursive case: if dth day doesn't exist in set 
    if(!s.has(d)) return findMinimumCostRec(d + 1);

    // recursive case: f(d) = min(costs[0]+f(d+1), costs[1]+f(d+8), costs[2]+f(d+30))
    let ans = Math.min(cArr[0]+findMinimumCostRec(d+1), cArr[1]+findMinimumCostRec(d+7), cArr[2]+findMinimumCostRec(d+30));

    return ans;
}

let mincostTickets = function(days, costs) {
    s = new Set(days);
    dArr = days;
    cArr = costs;
    return findMinimumCostRec(days[0]);
};

// let days = [1,4,6,7,8,20];
// let costs = [2,7,15];

let days = [1,2,3,4,5,6,7,8,9,10,30,31];
let costs = [2,7,15];
let ans = mincostTickets(days, costs);
console.log(ans);
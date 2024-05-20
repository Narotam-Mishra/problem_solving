
// Problem link - https://leetcode.com/problems/richest-customer-wealth/

// Approach - 1

let maximumWealth = function(accounts) {
    let maxWealth = 0;

    for(let p=0; p<accounts.length; p++) {
        let rSum = 0;
        for(let a=0; a<accounts[p].length; a++) {
            rSum += accounts[p][a];
        }
        maxWealth = Math.max(maxWealth, rSum);
    }
    return maxWealth;
};

// Problem link - https://leetcode.com/problems/minimum-penalty-for-a-shop/?envType=daily-question&envId=2025-12-26

let bestClosingTime1 = function(customers) {
    const n = customers.length;

    // keep track of penalty when shop is opened
    const prefixN = new Array(n+1).fill(0);
    prefixN[0] = 0;

    // keep track of penalty when shop is closed
    const suffixY = new Array(n+1).fill(0);
    suffixY[n] = 0;

    // step 1 - fill prefix when shop is opened
    for(let i=1; i<=n; i++){
        if(customers[i-1] == 'N'){
            prefixN[i] = prefixN[i-1] + 1;
        }else{
            prefixN[i] = prefixN[i-1];
        }
    }

    // step 2 - fill suffix when shop is closed
    for(let i=n-1; i>=0; i--){
        if(customers[i] == 'Y'){
            suffixY[i] = suffixY[i+1] + 1;
        }else{
            suffixY[i] = suffixY[i+1];
        }
    }

    // step 3 - calculate minimum penalty in earliest hour
    let minPenalty = Infinity;
    let minHour = Infinity;
    for(let i=0; i<=n; i++){
        let currPenalty = prefixN[i] + suffixY[i];
        if(currPenalty < minPenalty){
            minPenalty = currPenalty;
            minHour = i;
        }
    }

    // step 4 - return earliest hour
    return minHour;
};

let bestClosingTime = function(customers) {
    const n = customers.length;

    // initially all shops will be closed,
    // so current penalty will be count of `Y`
    let currPenalty = 0;
    for (let j = 0; j < n; j++) {
        if (customers.charAt(j) == 'Y') {
            currPenalty++;
        }
    }

    // keep track of minimum penalty and earlier hour
    let minPenalty = currPenalty;
    let minHour = 0;

    // step 1 - iterate on i-th hour
    for (let i = 0; i < n; i++) {
        // step 2 - calculate penalty for each hour
        if (customers.charAt(i) == 'Y') {
            currPenalty--;
        } else {
            currPenalty++;
        }

        // step 3 - update minimum penalty
        if (currPenalty < minPenalty) {
            minPenalty = currPenalty;

            // update earlier-hour
            minHour = i + 1;
        }
    }

    // step 4 - return the earliest hour at which the shop must be closed
    return minHour;
};

const customers = "YYNY";

// const customers = "NNNNN";

// const customers = "YYYY";
console.log(bestClosingTime(customers));
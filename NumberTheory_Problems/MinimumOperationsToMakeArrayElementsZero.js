
// Problem link - https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/description/?envType=daily-question&envId=2025-09-06

// Approach - Brute Force (Getting TLE)
let minOperations1 = function(queries) {
    // step 1 - utility function to calculate operations needed for a single number
    function getOperationsForNumber(x){
        if(x === 0) return 0;

        // calculate ceil(log4(x+1)) efficiently
        // log4(x) = log(x) / log(4) = log(x) / (2 * log(2))
        return Math.ceil(Math.log(x + 1) / Math.log(4));
    }

    // store sum of the result for all queries
    let totalSum = 0;

    // step 2 - process each query
    for(let i=0; i<queries.length; i++){
        // extract [l, r]
        const [l, r] = queries[i];
        let opNeeded = 0;

        // step 3 - calculate total operations needed for all numbers in range [l, r]
        for(let num=l; num<=r; num++){
            opNeeded += getOperationsForNumber(num);
        }

        // we can operate on two numbers simultaneously
        // step 4 - So the actual operations needed is ceil(total_operations / 2)
        const minOp = Math.ceil(opNeeded / 2);
        totalSum += minOp;
    }

    // step 5 - return sum of the result for all queries
    return totalSum;
};

// utility method to calculate total operations needed for all numbers in range [l, r]
function findSteps(l, r) {
    // start of current operation level range (4^0 = 1)
    let L = 1;     
    
    // current operation level (operations needed for this range)
    let steps = 1;
    
    // accumulator for total operations
    let actualSteps = 0;    
    
    // step 1 - process each operation level until we exceed the query range
    while (L <= r) {
        // step 2 - calculate end of current level range [L, R]
        // numbers needing 'steps' operations are in range [4^(steps-1), 4^steps - 1]
        const R = 4 * L - 1;  // End of current level
        
        // step 3 - find intersection of level range [L, R] with query range [l, r]
        const start = Math.max(L, l);  // left boundary of intersection
        const end = Math.min(R, r);    // right boundary of intersection
        
        // step 4 - if valid intersection exists, add its contribution
        if (start <= end) {
            // number of integers in intersection * operations per integer
            const count = end - start + 1;
            actualSteps += count * steps;
        }
        
        // step 5 - move to next operation level
        steps++;    // next level needs one more operation
        L *= 4;     // next level starts at 4^steps
    }
    
    // step 6 - return total operations accumulator
    return actualSteps;
}

let minOperations = function(queries) {
    // store final answer in `ans`
    let ans = 0;
    
    // step 1 - process each query independently
    for (const [l, r] of queries) {
        // step 2 - calculate total operations needed for range [l, r]
        const totalSteps = findSteps(l, r);
        
        // step 3 - apply pairing optimization
        // We can operate on 2 numbers simultaneously in each operation
        // So minimum operations = ceil(totalSteps / 2)
        // Using integer arithmetic: ceil(a/b) = (a + b - 1) / b = (a + 1) / 2 for b=2
        const minOpsForQuery = Math.floor((totalSteps + 1) / 2);
        
        ans += minOpsForQuery;
    }

    // step 4 - return final answer `ans`
    return ans;
};

const queries = [[1,2],[2,4]];

// const queries = [[2,6]];
console.log(minOperations(queries));
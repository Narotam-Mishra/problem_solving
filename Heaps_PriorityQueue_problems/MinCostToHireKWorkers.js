
// Problem link - https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/

// BruteForce Approach
let mincostToHireWorkers = function(quality, minWage, k) {
    const n = quality.length;
    let minCost = Number.MAX_VALUE;

    // iterate over each worker to consider them as the manager
    for(let manager = 0; manager < n; manager++){
        // calculate the ratio of minWage to quality for the manager
        const managerRatio = minWage[manager] / quality[manager];
        
        // array to store actual (valid) wages for each worker
        const validWages = [];

        // check each worker's wage when hired by this manager
        for(let worker = 0; worker < n; worker++){
            const workerWage = managerRatio * quality[worker];

            if(workerWage >= minWage[worker]){
                // if the calculated worker's wage is greater than or equal to the worker's minimum wage
                // that will be only valid
                validWages.push(workerWage);
            }
        }

        if(validWages.length < k){
            // if we don't have enough valid workers, 
            // continue to the next manager
            continue;
        }

        // sort the valid wages in ascending order
        // as we need to find the least amount of wage
        validWages.sort((a,b) => a - b);
        let totalWage = 0;

        // sum the smallest k wages
        for(let i=0; i<k; i++){
            totalWage += validWages[i];
        }

        // update the minimum cost if we found a cheaper combination
        minCost = Math.min(minCost, totalWage);
    }
    return minCost;
};

// const quality = [10, 20, 5];
// const minWage = [70, 50, 30];
// const k = 2;

const quality = [3,1,10,10,1], minWage = [4,8,2,2,7], k = 3
console.log(mincostToHireWorkers(quality, minWage, k));
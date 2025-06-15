
// Problem link - https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/?envType=problem-list-v2&envId=sliding-window

// Using Brute Force Approach 
let minimumRecolors1 = function(blocks, k) {
    const n = blocks.length;
    let minOperations = Infinity;

    // step 1 - check every possible window of size k
    for(let i=0; i<=n-k; i++){
        let whiteCount = 0;

        // step 2 - count white blocks in current window [i, i+k-1]
        for(let j=i; j<i+k; j++){
            if(blocks[j] === 'W'){
                whiteCount++;
            }
        }

        // step 3 - update minimum operations
        minOperations = Math.min(minOperations, whiteCount);

        // step 4 - early termintion
        if(minOperations == 0){
            break;
        }
    }

    // step 5 - return minimum operations, `minOperations`
    return minOperations;
};

// Optmized Approach using Sliding Window
let minimumRecolors = function(blocks, k) {
    const n = blocks.length;
    let whiteCount = 0;

    // step 1 - count white blocks in first k-window
    for(let i=0; i<k; i++){
        if(blocks[i] === 'W'){
            whiteCount++;
        }
    }

    // step 2 - initialize minimum operations with first window
    let minOperations = whiteCount;
    
    // step 3 - slide the window across the remaining string starting from `k`
    for(let i=k; i<n; i++){
        // step 4 - remove leftmost character from window if that is white `W`
        if(blocks[i-k] === 'W'){
            whiteCount--;
        }

        // step 5 - add new chracter to the rightmost window, if that is white `W`
        if(blocks[i] === 'W'){
            whiteCount++;
        }

        // step 6 - update minimum operations
        minOperations = Math.min(minOperations, whiteCount);

        // early termintion
        if(minOperations == 0){
            break;
        }
    }

    // step 7 - return minimum operations, `minOperations`
    return minOperations;
};

const blocks = "WBBWWBBWBW", k = 7;

// const blocks = "WBWBBBW", k = 2;
console.log(minimumRecolors(blocks, k));
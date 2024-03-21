
// Problem link - https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

// Approach - using Two Pointers Merge sort

let successfulPairs = function(spells, potions, success) {
    // Create pairs array to store spell strength and index
    const pairs = spells.map((strength, index) => ({strength, index}));

    // sort pairs array by strength
    pairs.sort((a,b) => a.strength - b.strength);

    // sort potions array in decreasing order
    potions.sort((a,b) => b - a);

    const m = potions.length;
    const n = spells.length
    // array to store success pairs count
    let successPairs = Array(n).fill(0);

    // for each spell of spells count successful pairs for each spell
    for(let i=0, j=0; i<n; ++i){
        while((j < m) && (potions[j] * pairs[i].strength >= success)){
            ++j;
        }
        // update the count of successful pairs at the original spell index
        successPairs[pairs[i].index] = j;
    }
    // Return array with counts of successful pairs for each spell in original order
    return successPairs;
};

// let spells = [5,1,3];
// let potions = [1,2,3,4,5];
// let success = 7;

let spells = [3,1,2];
let potions = [8,5,8];
let success = 16;

let res = successfulPairs(spells, potions, success);
console.log("Sucessful pair array:",...res);

// Problem link - https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/?envType=daily-question&envId=2025-11-10

let minOperations = function(nums) {
    let ops = 0;

    // stack to maintain increasing sequence of values
    let st = []; 

    // step 1 - iterate on each num of `nums`
    for(let num of nums) {
        // step 2 - remove all elements from stack that are greater than current number
        //this is because we can extend previous operations to cover current element
        while(st.length > 0 && st[st.length - 1] > num) {
            st.pop();
        }
        
        // skip zeros as they don't need any operations
        if(num === 0) continue;
        
        // step 3 - if stack is empty or current number is greater than stack top,
        // we need a new operation starting from this position
        if(st.length === 0 || st[st.length - 1] < num) {
            ops++; // Increment operation count
            st.push(num); // Add current number to our increasing sequence
        }
    }

    // step 4 - return minimum operation `ops`
    return ops;
};

// const nums = [0,2];

// const nums = [3,1,2,1];

const nums = [1,2,1,2,1,2];
console.log(minOperations(nums));
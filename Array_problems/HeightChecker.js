
// Problem link - https://leetcode.com/problems/height-checker/description/?envType=problem-list-v2&envId=array

let heightChecker = function(heights) {
    // step 1 - create a sorted version of the heights array to get the expected order
    const expected = [...heights].sort((a,b) => a - b);

    // step 2 - iterate on each array's elements and 
    let count = 0;
    for(let i=0; i<heights.length; i++){
        // step 3 - count the number of indices where heights[i] != expected[i].
        if(heights[i] !== expected[i]) count++;
    }

    // step 4 - return count
    return count;
};

// const heights = [1,1,4,2,1,3];

// const heights = [5,1,2,3,4];

const heights = [1,2,3,4,5];
console.log(heightChecker(heights));
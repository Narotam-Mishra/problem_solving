
// Problem link - https://leetcode.com/problems/make-array-elements-equal-to-zero/description/?envType=daily-question&envId=2025-10-28

let countValidSelections = function(nums) {
    // find size of input array `nums`
    const n = nums.length;

    // step 1 - helper function simulate starting at index `start` with initial direction `dir`
    function simulate(start, dir){
        // make a copy of original array
        const arr = [...nums];
        let curr = start;

        // iterate till pointer is within the array
        while(curr >= 0 && curr < n){
            // check if current cell is `0`, 
            if(arr[curr] === 0){
                // then just step in current direction
                curr += dir;
            }else{
                // otherwise decrement it, reverse direction, then take a step in new direction
                arr[curr] -= 1;
                dir = -dir;
                curr += dir;
            }
        }

        // at end check if every element became 0
        for(let num of arr){
            if(num !== 0) return false;
        }
        return true;
    }

    // store number of possible valid selections
    let count = 0;

    // step 2 - iterate on each number of nums
    for(let i=0; i<n; i++){
        // step 3 - skip non-zero values
        if(nums[i] !== 0) continue;

        // step 4 - simulate process in both directions
        if(simulate(i, +1)) count++;
        if(simulate(i, -1)) count++;
    }

    // step 5 - return number of possible valid selections
    return count;
};

// const nums = [1,0,2,0,3];

const nums = [2,3,4,0,4,1,0];
console.log(countValidSelections(nums));
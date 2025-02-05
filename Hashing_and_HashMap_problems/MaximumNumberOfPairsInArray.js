
// Problem link : https://leetcode.com/problems/maximum-number-of-pairs-in-array/?envType=problem-list-v2&envId=hash-table

let numberOfPairs = function(nums) {
    // step 1 - create frequency array map to count frquency of each array elements
    const freqMapArr = new Array(101).fill(0);
    for(let i=0; i<nums.length; i++){
        freqMapArr[nums[i]]++;
    }

    // step 2 - calculate number of pairs and number of left over elements from frequency array map 
    let numOfPairs = 0, numOfleftOvers = 0;
    for(let count of freqMapArr){
        // count how many pairs can be formed
        numOfPairs += Math.floor(count / 2);

        // count remaining unpaired numbers
        numOfleftOvers += count % 2;
    }

    // step 3 - return required result
    return [numOfPairs, numOfleftOvers];
};

// const nums = [1,3,2,1,3,2,2];

// const nums = [1,1];

const nums = [0];
console.log(numberOfPairs(nums));

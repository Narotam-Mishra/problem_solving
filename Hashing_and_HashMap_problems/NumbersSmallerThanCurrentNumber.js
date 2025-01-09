
// Problem link : https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/?envType=problem-list-v2&envId=hash-table

let smallerNumbersThanCurrent = function(nums) {
    // step 1 - create an array of pairs (value, index)
    let pairs = nums.map((num, index) => [num, index]);

    // step 2 - sort the array by the value of each element
    pairs.sort((a, b) => a[0] - b[0]);

    // step 3 - create a map to store the count of smaller numbers for each number
    let smallerCounts = {};

    // step 4 - iterate through the sorted array and assign counts based on the index
    for(let i=0; i<pairs.length; i++) {
        // only assign if the number hasn't been assigned yet (to handle duplicates)
        if(smallerCounts[pairs[i][0]] === undefined){
            smallerCounts[pairs[i][0]] = i;
        }
    }

    // step 5 - build the result array and return res
    // for each number in the original array, use the hash map to find the count
    const res = nums.map((num) => smallerCounts[num]);
    return res;
};

// const nums = [8,1,2,2,3];

// const nums = [6,5,4,8];

// const nums = [6,5,4,8];

const nums = [7, 7, 7, 7];
console.log(smallerNumbersThanCurrent(nums));


// Problem link - https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/description/?envType=problem-list-v2&envId=hash-table

let sumCounts1 = function(nums) {
    // store total sum of distinct subarray count
    let totalSum = 0;

    // step 1 - iterate oover all possible starting points of subarrays
    for(let i = 0; i < nums.length; i++) {
        // stor unique elements in current subarray
        const numSet = new Set();

        // step 2 - iterate over all possible ending points of subarrays starting at i
        for(let j=i; j<nums.length; j++) {
            // add current subarray element to set
            numSet.add(nums[j]);

            // step 3 - calculate the distinct count and its square, then add to the total sum
            const distinctCount = numSet.size;
            totalSum += (distinctCount * distinctCount);
        }
    }

    // step 4 - return the total sum
    return totalSum;
};

let sumCounts = function(nums) {
    // store total sum of distinct subarray count
    let totalSum = 0;

    // step 1 - iterate over all possible starting points of subarrays
    for (let i = 0; i < nums.length; i++) {
        // store unique elements in frequency map
        const freqMap = new Array(101).fill(0);

        // track distinct element count
        let distinctCount = 0;

        // step 2 - iterate over all possible ending points of subarrays starting at i
        for (let j = i; j < nums.length; j++) {
            // if element is not present in subarray
            if (freqMap[nums[j]] === 0) {
                distinctCount++;
            }

            // increment frequency of current element
            freqMap[nums[j]]++;

            // step 3 - calculate the distinct count and its square
            totalSum += (distinctCount * distinctCount);
        }
    }
    // step 4 - return the total sum
    return totalSum;  
};

const nums = [1, 2, 1];

// const nums = [1, 1];
console.log(sumCounts(nums)); 

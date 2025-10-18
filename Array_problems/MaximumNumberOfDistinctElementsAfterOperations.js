
// Problem link - https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description/?envType=daily-question&envId=2025-10-18

let maxDistinctElements = function(nums, k) {
    // find size of input array `nums` 
    let n = nums.length;

    // step 1 - sort input array `nums` to process elements in ascending order
    nums.sort((a,b) => a - b);

    // step 2 - keep track of previously updated element
    // we need this to ensure the next element gets a value > prev (distinct)
    let prevVal = -Infinity;

    // step 3 - iterate through each element in the sorted array
    let count = 0;
    for(let i=0; i<n; i++){
        // step 4 - calculate the minimum possible value for current element
        let minVal = nums[i] - k;

        // case 1 - if previous value is less than the minimum possible
        // value this means there's a gap, and we can place current element at its minimum
        if(prevVal < minVal){
            prevVal = nums[i] - k;

            // increment count for this distinct element
            count++;
        }

        // case 2 - if previous value is within or just before the valid
        // range check if prev is less than the maximum possible value
        // (nums[i]+k)
        else if(prevVal < nums[i]+k){
            // this means we can place the element just after prev
            prevVal = prevVal + 1;
                
            // increment count for this distinct element
            count++;
        }
    }

    // step 5 - return the total count of distinct elements we could create
    return count;
};

// const nums = [1,2,2,3,3,4], k = 2;

const nums = [4,4,4,4], k = 1;
console.log(maxDistinctElements(nums, k));
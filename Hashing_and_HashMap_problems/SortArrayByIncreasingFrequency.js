
// Problem link : https://leetcode.com/problems/sort-array-by-increasing-frequency/?envType=problem-list-v2&envId=hash-table

let frequencySort = function(nums) {
    // step 1 - count the frequency of each element
    const frqMap = {};
    for(let num of nums){
        frqMap[num] = (frqMap[num] || 0) + 1;
    }

    // step 2 - sort the array with a custom comparator
    // case 1 - first sort by frequency (ascending)
    // case 2 - if frequencies are the same, sort by value (descending)
    nums.sort((a,b) => {
        // get frequency of element 'a'
        const frqA = frqMap[a];

        // get frequency of element 'b'
        const frqB = frqMap[b];

        // step 3 -  if frequencies are equal, sort by value (descending)
        if(frqA === frqB){
            return b - a;
        }

        // step 4 - otherwise, sort by frequency (ascending)
        return frqA - frqB;
    })

    // step 5 - return the sorted array
    return nums;
};

// const nums = [1,1,2,2,2,3];

const nums = [2,3,1,3,2];
console.log(frequencySort(nums));

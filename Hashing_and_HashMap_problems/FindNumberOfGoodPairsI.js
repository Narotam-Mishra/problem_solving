
// Problem link : https://leetcode.com/problems/find-the-number-of-good-pairs-i/description/?envType=problem-list-v2&envId=hash-table

// Approach 1 : Brute Force
let numberOfPairs1 = function(nums1, nums2, k) {
    // step 1 - intialize variable to count good pairs
    let goodPairsCount = 0;

    // step 2 - loop through both arrays
    for(let i=0; i<nums1.length; i++) {
        for(let j=0; j<nums2.length; j++) {
            // step 3 - check if the number is divisible by the product of the number in the second array and k
            if(nums1[i] % (nums2[j] * k) === 0){
                goodPairsCount++;
            }
        }
    }

    // step 4 - return the count of good pairs
    return goodPairsCount;
};

let numberOfPairs = function(nums1, nums2, k) {
    // step 1 - create a hash map to store frequencies of nums2[j] * k
    const divisorMap = new Map();
    for(const num of nums2){
        const divisor = num * k;
        divisorMap.set(divisor, (divisorMap.get(divisor) || 0) + 1);
    }

    // step 2 - iterate through nums1 and count good pairs
    let goodPairsCount = 0;
    for(const num of nums1){
        for(const [divisor, count] of divisorMap.entries()){
            if(num % divisor === 0){
                // add the count of this divisor to the result
                goodPairsCount += count;
            }
        }
    }

    // step 3 - return count of all good pairs
    return goodPairsCount;
};

// const nums1 = [1,3,4], nums2 = [1,3,4], k = 1;

const nums1 = [1,2,4,12], nums2 = [2,4], k = 3;
console.log(numberOfPairs(nums1, nums2, k)); 
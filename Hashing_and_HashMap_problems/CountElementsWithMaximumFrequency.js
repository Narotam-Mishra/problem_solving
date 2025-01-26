
// Problem link : https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=problem-list-v2&envId=hash-table

let maxFrequencyElements = function(nums) {
    // step 1 - create a frequency map using array
    const freq = new Array(101).fill(0);
    for(let i=0; i<nums.length; i++) {
        freq[nums[i]]++;
    }

    // step 2 - find the maximum frequency
    let maxFreq = 0;
    for(const frequency of freq) {
        maxFreq = Math.max(maxFreq, frequency);
    }

    // step 3 - sum up the frequencies of elements with the maximum frequency
    let totalFrquency = 0;
    for(const frequency of freq){
        if(frequency === maxFreq) {
            totalFrquency += frequency;
        }
    }

    // step 4 - return the total frequency
    return totalFrquency;
};

// const nums = [1,2,2,3,1,4];

// const nums = [1,2,3,4,5];

// const nums = [15];

const nums = [81,81,81,81,81,81,81,17,28,81,81,56,81,54,81,81,81,81,81,60,81,28,81,81,81,81,81,54,81,81,81,81,100,28];
console.log(maxFrequencyElements(nums));
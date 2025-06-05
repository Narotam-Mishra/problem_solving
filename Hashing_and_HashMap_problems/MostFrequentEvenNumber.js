
// Problem link - https://leetcode.com/problems/most-frequent-even-element/description/

let mostFrequentEven = function(nums) {
    // step 1 - find frequency of each number in `frqMap`
    let frqMap = {};
    for(let num of nums){
        frqMap[num] = (frqMap[num] || 0) + 1;
    }
    
    // step 2 - find most frquent event element by iterating on frquency map
    let ans = -1, maxFrq = -1;
    for(let key in frqMap){
        if(Number(key) % 2 === 0 && frqMap[key] > maxFrq){
            ans = Number(key);
            maxFrq = frqMap[key];
        }
    }

    // step 3 - return the ans
    return ans;
};

// const nums = [0,1,2,2,4,4,1];

// const nums = [4,4,4,9,2,4];

// const nums = [29,47,21,41,13,37,25,7];

const nums = [10000];
console.log(mostFrequentEven(nums));


// Problem link - https://leetcode.com/problems/sum-of-subarray-minimums/description/

// Approach - 1 (Brute force approach)

let sumSubarrayMins1 = function(arr) {
    let subSum = 0;
    const modNum = 1000000007;
    for(let i=0; i<arr.length; i++){
        let minNum = arr[i];
        for(let j=i; j<arr.length; j++){
            minNum = Math.min(minNum, arr[j]);
            subSum += minNum;
        }
    }
    return subSum % modNum;
};

// Approach - 2 ()

let sumSubarrayMins = function(arr) {
    
};

let arr = [11,81,94,43,3];
console.log(sumSubarrayMins(arr));
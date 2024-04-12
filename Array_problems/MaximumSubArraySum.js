
//Problem link -  https://leetcode.com/problems/maximum-subarray/

// find maximum subarray sum in array (using kadane's Algorithm)

let maximumSubarraySum = function (arr){
    let curSum = arr[0];
    let maxSum = arr[0];

    for(let i=1; i<arr.length; i++){
        // find maximum ccurrent sum
        curSum = Math.max(arr[i], curSum+arr[i]);

        // update maximum sum
        maxSum = Math.max(curSum, maxSum);
    }
    return maxSum;
}

let arr = [-2,1,-3,4,-1,2,1,-5,4];
let maxSum = maximumSubarraySum(arr);
console.log(maxSum);
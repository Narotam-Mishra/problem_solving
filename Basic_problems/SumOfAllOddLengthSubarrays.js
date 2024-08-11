
// Problem link : https://leetcode.com/problems/sum-of-all-odd-length-subarrays/description/

let sumOddLengthSubarrays = function(arr) {
    let totalSum = 0;
    let len = arr.length;

    for(let i=0; i<arr.length; i++){
        // the total number of subarrays that include arr[i]
        let subArrCount = (i + 1) * (len - i);

        // the number of odd-length subarrays that include arr[i]
        let oddLenSubArrCount = Math.floor((subArrCount + 1) / 2);

        // add to the total sum the contribution of arr[i]
        totalSum += arr[i] * oddLenSubArrCount;
    }
    return totalSum;
};

let arr = [1, 4, 2, 5, 3];
console.log(sumOddLengthSubarrays(arr));

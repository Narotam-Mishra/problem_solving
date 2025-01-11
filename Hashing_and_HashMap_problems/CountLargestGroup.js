
// Problem link : https://leetcode.com/problems/count-largest-group/description/?envType=problem-list-v2&envId=hash-table

// utility function to find digit sum
function getDigitSum(num){
    let sum = 0;
    while(num > 0){
        sum += num % 10;
        num = Math.floor(num / 10);
    }
    return sum;
}

let countLargestGroup = function(n) {
    // step 1 - use map to store the size of each digit sum group
    const digitSumMap = {};

    // step 2 - group numbers by their digit sums
    for(let i=1; i<=n; i++){
        let digitSum = getDigitSum(i);
        digitSumMap[digitSum] = (digitSumMap[digitSum] || 0) + 1;
    }

    // step 3 - find the largest group size
    const maxGroupSize = Math.max(...Object.values(digitSumMap));

    // step 4 - count how many groups have the largest size
    const largestGroupCount = Object.values(digitSumMap).filter((size) => size === maxGroupSize).length;

    // step 5 - return the largest group count
    return largestGroupCount;
};

// const num = 13;

const num = 2;
console.log(countLargestGroup(num));

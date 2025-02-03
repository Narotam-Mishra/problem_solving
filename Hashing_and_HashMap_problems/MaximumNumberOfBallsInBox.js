
// Problem link : https://leetcode.com/problems/maximum-number-of-balls-in-a-box/description/?envType=problem-list-v2&envId=hash-table

// utility function to calculate sum of digits
function findSumOfDigits(num){
    let sum = 0;
    while(num > 0){
        sum += num % 10;
        num = Math.floor(num/10);
    }

    return sum;
}

let countBalls1 = function(lowLimit, highLimit) {
    // step 1 - map to store the count of balls in each box
    let boxMap = {};

    // step 2 - iterate through all ball numbers
    for(let i=lowLimit; i<=highLimit; i++){
        let boxNumber = findSumOfDigits(i);

        // update the count in hashmap
        boxMap[boxNumber] = (boxMap[boxNumber] || 0) + 1;
    }

    // step 3 - find the maximum number of balls in any box
    return Math.max(...Object.values(boxMap));
};

let countBalls = function(lowLimit, highLimit) {
    // step 1 - box map array to store the count of balls in each box
    const boxMapArr = new Array(47).fill(0);

    // step 2 - iterate through all ball numbers
    for(let i=lowLimit; i<=highLimit; i++){
        let boxNumber = findSumOfDigits(i);

        // update the count in box map array
        boxMapArr[boxNumber]++;
    }

    // step 3 - find the maximum number of balls in any box
    return Math.max(...boxMapArr);
}

const lowLimit = 1, highLimit = 10;

// const lowLimit = 5, highLimit = 15;

// const lowLimit = 19, highLimit = 28;
console.log(countBalls(lowLimit, highLimit));


// Problem link : https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/?envType=problem-list-v2&envId=number-theory&status=TO_DO&difficulty=EASY

// helper function to calculate the greatest common divisor (GCD) using Euclid's algorithm
function getGCD(a, b){
    while(b !== 0){
        const temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

let findGCD = function(nums) {
    // find maximum number from array
    let maxNum = Math.max(...nums);

    // find minimum number from array
    let minNum = Math.min(...nums);

    // find and return GCD of maximum and minimum number
    return getGCD(minNum, maxNum);
};

// let nums = [2,5,6,9,10];

let nums = [7, 5, 6, 8, 3];
console.log(findGCD(nums));

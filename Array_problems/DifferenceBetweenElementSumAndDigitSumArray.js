
// Problem link - https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/?envType=problem-list-v2&envId=array

// utlity function to find sum of array's elements digit sum
function findDigitSum(arr){
    let digitSum = 0;
    for(let num of arr){
        if(num <= 9){
            digitSum += num;
        }else{
            while(num > 0){
                digitSum += num % 10;
                num = Math.floor(num/10)
            }
        }
    }
    return digitSum;
}

// utlity function to find sum of array's elements
function findArraySum(arr){
    let sum = 0;
    for(let num of arr){
        sum += num;
    }
    return sum;
}

let differenceOfSum = function(nums) {
    // step 1 - get array's element sum
    const elementSum = findArraySum(nums);

    // step 2 - get array's digit sum
    const digitSum = findDigitSum(nums);

    // step 3 - find and return the absolute difference between the element sum and digit sum
    return Math.abs(elementSum - digitSum);
};

// const nums = [1,15,6,3];

const nums = [1,2,3,4];
console.log(differenceOfSum(nums));
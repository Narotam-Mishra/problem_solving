
// Problem link - https://leetcode.com/problems/check-if-any-element-has-prime-frequency/description/?envType=problem-list-v2&envId=array

// utility function to check i a prime number
function isPrimeNumber(num){
    // cornor case
    if(num <= 1) return false;

    // check prime number from 2 to sqrt(n)
    for(let i=2; i<= Math.floor(Math.sqrt(num)); i++){
        if(num % i === 0) return false;
    }

    return true;
}

let checkPrimeFrequency = function(nums) {
    // step 1 - create frequency array to store frquency of `nums` elements
    const frqArr = new Array(101).fill(0)

    // step 2 - count frequency of each `nums` element
    for(let num of nums){
        frqArr[num]++;
    }

    // step 3 - iterate on frequency array
    for(let num of frqArr){
        // step 4 - check if any frquency has prime frequency
        if(isPrimeNumber(num)){
            return true;
        }
    }

    // step 5 - if none of the frequency is prime then return false
    return false;
};

// const nums = [1,2,3,4,5,4];

// const nums = [1,2,3,4,5];

const nums = [2,2,2,4,4,];
console.log(checkPrimeFrequency(nums))
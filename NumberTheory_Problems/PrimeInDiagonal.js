
// Problem link - https://leetcode.com/problems/prime-in-diagonal/description/?envType=problem-list-v2&envId=number-theory

// utility function to check if number is prime or not
function isPrime(num){
    // base case
    if(num <= 1){
        return false;
    }

    // iterate of number from 2 to sqrt(n)
    for(let i=2; i*i <= num; i++){
        if(num % i === 0){
            // return false immediately if it is divisble by any number
            return false;
        }
    }

    // otherwise return true
    return true;
}

let diagonalPrime = function(nums) {
    // step 1 - store maximum Prime number ina variable `maxPrime`
    let maxPrime = 0;

    // find number of rows
    const n = nums.length;

    // step 2 - iterate on 2D array
    for(let i=0; i<n; i++){
        // step 3 - get primary diagonal elements
        let primary = nums[i][i];

        // step 4 - get secondary diagonal elements
        let secondary = nums[i][n-i-1];

        // step 5 - check and update maxPrime for Primary and secondary elements
        if(isPrime(primary)){
            maxPrime = Math.max(maxPrime, primary);
        }

        if(isPrime(secondary)){
            maxPrime = Math.max(maxPrime, secondary);
        }
    }

    // step 6 - return maxPrime
    return maxPrime;
};

// const nums = [[1,2,3],[5,6,7],[9,10,11]];

const nums = [[1,2,3],[5,17,7],[9,11,10]];
console.log(diagonalPrime(nums));

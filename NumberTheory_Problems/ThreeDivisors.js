
// Problem link : https://leetcode.com/problems/three-divisors/description/?envType=problem-list-v2&envId=number-theory&status=TO_DO%2CATTEMPTED&difficulty=EASY

function isPrime(n){
    // corner case
    if(n <= 1){
        return false
    }

    // check from 2 to sqrt(n)
    for(let i=2; i <= Math.floor(Math.sqrt(n)); i++){
        if(n % i === 0) return false;
    }
    return true;
}

let isThree = function(n) {
    // check if n is a perfect square
    let sqrtNum = Math.sqrt(n);


    if(sqrtNum !== Math.floor(sqrtNum)){
        // not a perfect square
        return false;
    }

    // check if the square root of n is a prime number
    return isPrime(sqrtNum);
};

// let n = 2;

// let n = 4;

let n = 12;
console.log(isThree(n));


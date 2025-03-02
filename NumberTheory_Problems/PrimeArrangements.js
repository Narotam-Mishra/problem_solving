
// Problem link - https://leetcode.com/problems/prime-arrangements/?envType=problem-list-v2&envId=math

// utlity function to calculate factorial of a number
function getFactorialValue(num, mod){
    let fVal = BigInt(1);
    for(let i=1; i<=num; i++){
        fVal = (fVal * BigInt(i)) % BigInt(mod);
    }
    return fVal;
}

// utility function to precompute prime numbers in an array
function preComputePrimeNumber(){
    const primeArr = new Array(101).fill(true);
    primeArr[0] = primeArr[1] = false; // 0 and 1 are not prime numbers

    for(let i = 2; i * i <= 100; i++){
        if(primeArr[i]){
            for(let j = i * i; j <= 100; j += i){
                primeArr[j] = false;
            }
        }
    }
    return primeArr;
}

let numPrimeArrangements = function(n) {
    const mod = 1000000007;

    // step 1 - pre compute prime numbers in array of size 100
    const primeArr = preComputePrimeNumber();
    
    // step 2 - count prime numbers from 1 to n
    let primeCount = 0;
    for(let i=1; i<=n; i++){
        if(primeArr[i]){
            primeCount++;
        }
    }

    // step 3 - find number of permutations for prime numbers
    const np = getFactorialValue(primeCount, mod);

    // step 4 - find number of permutations for non-prime numbers
    const nnp = getFactorialValue(n - primeCount, mod);

    // step 5 - compute the result and return it
    const res = (np * nnp) % BigInt(mod);
    return Number(res);
};

// const n = 5;

const n = 100;
console.log(numPrimeArrangements(n));

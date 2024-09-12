
// Problem link - https://leetcode.com/problems/count-primes/description/

// Approach - 1 (Brute Force Approach)
let isPrime = function(n){
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

let countPrimes1 = function(n) {
    let count = 0;

    for(let i=1; i<n; i++){
        if(isPrime(i)){
            count++;
        }
    }

    return count;
};

// Approach - 2 (using Prime sieve)
function primeSieve(maxN){
    const primes = new Array(maxN + 1).fill(0);

    // first mark all odd numbers as prime 
    for(let i=3; i<=maxN; i+=2){
        primes[i] = 1;
    }

    // prime sieve logic
    for(let i=3; i<=maxN; i+=2){
        // if the current number is not marked then it is prime
        if(primes[i] === 1){
            // mark all the multiples of i as not prime
            for(let j=i*i; j<=maxN; j+=i){
                primes[j] = 0;
            }
        }
    }

    // special cornor case:
    primes[2] = 1;
    primes[0] = primes[1] = 0;

    return primes;
}

let countPrimes = function(n) {
    let count = 0;

    // get all primes in an array
    const primes = primeSieve(n);

    // iterate through number in given range
    for(let i=1; i<n; i++){
        if(primes[i]) count++
    }
    // return count of prime numbers
    return count;
};

let num = 10;
console.log(countPrimes(10));

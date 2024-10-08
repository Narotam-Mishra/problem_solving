
// Problem link : https://www.geeksforgeeks.org/problems/prime-number2314/1

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

let num = 2;
console.log(isPrime(num));

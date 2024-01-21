
// Check given number is prime or not

function isPrimeNumber(num){
    for(let i=2; i<=num-1; i++){
        // we found a number in range [2, num-1], which divides number, 'num'
        // hence number is prime 'num' is not prime
        if(num % i === 0) return false;
    }
    // the loop completed but we didn't any number in the range [2, num-1] that can divide number, 'num'
    return true;
}

let n = 13;

if(isPrimeNumber(n)){
    console.log(`${n} is prime number`);
}else{
    console.log(`${n} is not prime number`);
}
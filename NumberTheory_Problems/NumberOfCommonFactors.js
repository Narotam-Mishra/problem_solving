
// Problem link : https://leetcode.com/problems/number-of-common-factors/description/?envType=problem-list-v2&envId=number-theory&status=TO_DO&difficulty=EASY

let commonFactors1 = function(a, b) {
    let commonFactorCount = 0;
    for(let i=1; i<=Math.max(a, b); i++){
        if(a % i === 0 && b % i === 0) commonFactorCount++;
    }
    return commonFactorCount;
};

// step 1 - utility method to find GCD of two numbers
function findGCD(x, y){
    while(y !== 0){
        let temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

let commonFactors = function (a, b) {
  // intialize counter to count common factors
  let commonFactorCount = 0;

  // step 2: Compute the GCD of a and b
  let gcdVal = findGCD(a, b);

  // step 3 : count divisors of the GCD
  for (let i = 1; i * i <= gcdVal; i++) {
    // count i as a factor
    if (gcdVal % i === 0) {
       commonFactorCount++;
      // count gcdVal/i as distinct factor
      if (i !== gcdVal / i) {
        commonFactorCount++;
      }
    }
  }
  // step 4: Return the count of common factors
  return commonFactorCount;
};

let a = 12, b = 6;

// let a = 25, b = 30;
console.log(commonFactors(a, b));

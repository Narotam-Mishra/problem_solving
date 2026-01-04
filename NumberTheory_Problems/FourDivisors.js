
// Problem link - https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04

/**
 * @param {number[]} nums
 * @return {number}
 */
let sumFourDivisors = function(nums) {
    const findDivisorSum = (num) => {
        // keep track of factors count and factors sum
        let factorsCount = 0;
        let divisorsSum = 0;

        // iterate on each possible factor from 1 to sqrt(n)
        for(let f = 1; f * f <= num; f++){
            // check if `num` is divisible
            if(num % f === 0){
                // find other factor
                let f2 = num / f;

                // check if num is perfect square number
                if(f === f2){
                    // count only one factor
                    factorsCount += 1;

                    // calculate factors sum
                    divisorsSum += f;
                } else {
                    // count factors in pair
                    factorsCount += 2;

                    // calculate factors sum
                    divisorsSum += (f + f2);
                }
            }

            // check if factors count is greater than 4 than return 0
            if(factorsCount > 4) return 0;
        }

        // return factors sum if factors count is exactly four otherwise 0
        return factorsCount === 4 ? divisorsSum : 0;
    };

    // keep track of factors sum
    let factorsSum = 0;

    // step 1 - iterate on each num of `nums`
    for(let num of nums){
        // step 2 - find factors sum
        factorsSum += findDivisorSum(num);
    }

    // step 3 - return factors sum, `factorsSum`
    return factorsSum;
};

// const nums = [21,4,7];

// const nums = [21,21];

const nums = [1,2,3,4,5];
console.log(sumFourDivisors(nums));
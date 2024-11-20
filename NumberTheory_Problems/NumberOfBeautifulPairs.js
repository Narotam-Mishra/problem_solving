
// Problem link : https://leetcode.com/problems/number-of-beautiful-pairs/description/?envType=problem-list-v2&envId=number-theory&status=TO_DO&difficulty=EASY

// helper function to extract the first digit of a number
function getFirstDigit(num){
    while(num >= 10){
        num = Math.floor(num / 10);
    }
    return num;
}

// helper function to extract the last digit of a number
function getLastDigit(num){
    return num % 10;
}

// helper function to calculate the greatest common divisor (GCD) using Euclid's algorithm
function gcd(a, b){
    while(b !== 0){
        const temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

let countBeautifulPairs = function(nums) {
    // initialize count of beautiful pairs
    let count = 0;
    
     // iterate over all pairs of indices (i, j) where i < j
    for(let i=0; i<nums.length; i++){
        for(let j = i+1; j<nums.length; j++){
            // extract the first digit of nums[i] and the last digit of nums[j]
            const x = getFirstDigit(nums[i]);
            const y = getLastDigit(nums[j]);
            
            // check if pair are coprime
            if(gcd(x, y) === 1){
                // increment count if the pair is beautiful
                count++;
            }
        }
    }
    return count;
};

// let nums = [2, 5, 1, 4];

let nums = [11,21,12];
console.log(countBeautifulPairs(nums));

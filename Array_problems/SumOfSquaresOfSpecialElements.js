
// Problem link : https://leetcode.com/problems/sum-of-squares-of-special-elements/description/

let sumOfSquares1 = function(nums) {
    // intialize a variable to store the sum of squares
    let ss = 0;
    
    // calculate length of array 
    const n = nums.length;
    
    // iterate over array elements
    for(let i=0; i<n; i++){
        // check for special elements
        if(n % (i+1) === 0){
            // find sum of squares if it is special element
            ss += (nums[i] * nums[i]);
        }
    }

    // return sum of squares `ss`
    return ss;
};

let sumOfSquares = function(nums) {
    // intialize a variable to store the sum of squares
    let ss = 0;
    
    // calculate length of array 
    const n = nums.length;
    
    // iterate over array elements
    for(let i=1; i<= Math.sqrt(n); i++){
        // check for special elements
        if(n % i === 0){
            // find sum of squares if it is special element
            ss += (nums[i-1] * nums[i-1]);

            // n / i is also a divisor, but avoid double counting when i == n / i
            if(i !== n / i){
                ss += (nums[n/i - 1] * nums[n/i - 1]);
            }
        }
    }

    // return sum of squares `ss`
    return ss;
};

// const nums = [1,2,3,4];

const nums = [2, 7, 1, 19, 18, 3];
console.log(sumOfSquares(nums));

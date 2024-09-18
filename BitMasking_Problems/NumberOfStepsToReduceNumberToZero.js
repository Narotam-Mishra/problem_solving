
// Problem link : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/?envType=problem-list-v2&envId=bit-manipulation

let numberOfSteps = function(num) {
    // edge case:
    if(!num) return 0

    // loop until num becomes 0
    let res = 0;
    while(num > 0){
        // if num is odd, subtract 1
        // otherwise If num is even, divide it by 2
        (num & 1) ? num-- : num /= 2;
        res++;
    }
    // return the total number of steps taken
    return res;
};

// let num = 123;

let num = 14;
console.log(numberOfSteps(num));

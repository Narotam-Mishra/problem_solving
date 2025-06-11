
// Problem link - https://leetcode.com/problems/find-the-k-beauty-of-a-number/description/?envType=problem-list-v2&envId=sliding-window

let divisorSubstrings = function(num, k) {
    // step 1 - convert to string for easy iteration
    const numStr = num.toString();
    const n = numStr.length;

    // edge case: if k is larger than the number of digits, no substrings possible
    if(k > n){
        return 0;
    }

    // step 2 - Sliding window approach: check all k-length substrings
    // count k-beauty of num
    let count = 0;
    for(let i=0; i<=n-k; i++){
        // step 3 - extract substring of length k starting at position i
        const subStr = numStr.substring(i, i+k);

        // step 4 - convert substring to integer to check divisibility
        const divisor = parseInt(subStr, 10);

        // step 5 - check given conditions for k-beauty
        if(divisor!==0 && num % divisor === 0){
            count++;
        }
    }

    // step 5 - return count (num of substring) that satisfy above condition
    return count;
};

// const num = 240, k = 2;

const num = 430043, k = 2;
console.log(divisorSubstrings(num, k));

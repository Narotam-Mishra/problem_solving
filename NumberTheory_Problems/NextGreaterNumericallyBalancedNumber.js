
// Problem link - https://leetcode.com/problems/next-greater-numerically-balanced-number/?envType=daily-question&envId=2025-10-24

let nextBeautifulNumber = function(n) {
    // utility method to check if number is balanced or not
    const isBalancedNumber = (num) => {
        const freq = new Array(10).fill(0);
        let temp = num;
        
        while (temp > 0) {
            const digit = temp % 10;
            freq[digit]++;
            temp = Math.floor(temp / 10);
        }
        
        for (let d = 0; d < 10; d++) {
            if (freq[d] > 0 && freq[d] !== d) {
                return false;
            }
        }
        return true;
    };
    
    // step 1 - iterate from n+1 to last balanced number in given range
    for (let i = n + 1; i <= 1224444; i++) {
        // step 2 - check if the number is balanced or not
        if (isBalancedNumber(i)) {
            // step 3 - return the balanced number immediately
            return i;
        }
    }
    
    // otherwise return -1
    return -1;
};

// const n = 1;

// const n = 1000;

const n = 3000;
console.log(nextBeautifulNumber(n));
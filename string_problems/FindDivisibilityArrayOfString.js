
// Problem link - https://leetcode.com/problems/find-the-divisibility-array-of-a-string/description/

let divisibilityArray = function(word, m) {
    // step 1 - use `div` array to store result
    const n = word.length;
    const div = new Array(n).fill(0);
    let currMod = 0;

    // step 2 - iterate on each digit of string `word`
    for(let i=0; i<n; i++){
        // step 3 - convert the current digit character to integer
        const digit = parseInt(word[i]);
        
        // step 4 - update the running modulo using rolling formula
        currMod = (currMod * 10 + digit) % m;
        
        // step 5 - if current number from word[0..i] is divisible by m, mark as 1
        if(currMod === 0){
            div[i] = 1;
        }
    }

    // step 6 - return resultant `div`
    return div;
};

// const word = "998244353", m = 3;

const word = "1010", m = 10;
console.log(divisibilityArray(word, m));

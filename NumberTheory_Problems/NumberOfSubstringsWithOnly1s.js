
// Problem link - https://leetcode.com/problems/number-of-substrings-with-only-1s/?envType=daily-question&envId=2025-11-16

let numSub1 = function(s) {
    const mod = 1e9 + 7;

    // store final result in res
    let res = 0;

    // step 1 - iterate on each character of s
    let count = 0;
    for (let ch of s) {
        // step 2 - count ones in current subsring
        if (ch === '1') {
            count++;
        } else {
            // step 3 - calculate number of substring possible
            res = (res + (count * (count + 1)) / 2) % mod;

            // step 4 - reset count of ones to 0 as streak of 1s break
            count = 0;
        }
    }

    // step 5 - calculate number of substring for last substring if exist
    if (count > 0) {
        res = (res + (count * (count + 1)) / 2) % mod;
    }

    // step 6 - return final result, res
    return res;
};

let numSub = function(s){
    const mod = 1e9 + 7;

    // store final result in res
    let res = 0;

    // step 1 - iterate on each substring of s
    let c = 0;
    for(let ch of s){
        // step 2 - count ones in each substring
        if(ch == '1'){
            c++;

            // calculate number of substring with 1s only
            res = (res + c) % mod;
        }else{
            // step 3 - reset count, c to 0 as 1s streaks break
            c = 0;
        }
    }

    // step 4 - return final result, res
    return res;
}

// const s = "0110111";

// const s = "101";

const s = "111111";
console.log(numSub(s));
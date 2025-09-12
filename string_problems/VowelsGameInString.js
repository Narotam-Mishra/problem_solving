
// Problem link - https://leetcode.com/problems/vowels-game-in-a-string/description/?envType=daily-question&envId=2025-09-12

let doesAliceWin = function(s) {
    // step 1 - count vowels in input string `s`
    let vowelsCount = 0;
    for(let ch of s){
        if(ch === 'a' || ch === 'e' || ch === 'i' || ch === 'o' || ch === 'u'){
            vowelsCount++;
        }
    }

    // step 2 - if vowels count is not zero then `Alice` wins, so return true
    // otherwise return false
    return vowelsCount ? true : false;
};

// const s = "leetcoder";

const s = "bbcd";
console.log(doesAliceWin(s));
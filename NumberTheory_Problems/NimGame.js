
// Problem link - https://leetcode.com/problems/nim-game/description/?envType=problem-list-v2&envId=brainteaser

let canWinNim = function(n) {
    // you can win if and only if n is not dvisible by 4
    return n % 4 !== 0;
};

// const n = 4;

// const n = 1;

const n = 2;
console.log(canWinNim(n));

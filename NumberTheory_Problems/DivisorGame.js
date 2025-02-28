
// Problem Link - https://leetcode.com/problems/divisor-game/description/?envType=problem-list-v2&envId=math

// Approach - 1 (using DP)
let divisorGame = function(n, cache={}) {
    // if `n` is already computed then return its value
    if(n in cache) return cache[n];

    // base case: if n is 1, Alice loses immediately
    if(n === 1) return false;

    // step 1 - iterate on all possible value of `n`
    for(let x=1; x<n; x++){
        // step 2 - if `x` is valid move and if that move make Bob lose then Alice wins
        if(x % n === 0 && !divisorGame(n-x, cache)){
            return (cache[n] = true);
        }
    }

    // step 3 - if no winning move is found, Alice lose
    return (cache[n] = false);
};

// Approach - 2 (Optimized)
let divisorGame1 = function(n) {
    // Alice wins if and only if `n` is even
    return n % 2 === 0;
};

const n = 2;

// const n = 3;
console.log(divisorGame(n));

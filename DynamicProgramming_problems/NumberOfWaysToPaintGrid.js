
// Problem link - https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/?envType=daily-question&envId=2026-01-03

let numOfWays = function(n) {
    // modulo value
    const MOD = 1_000_000_007;
    
    // predefined all valid color states for a row
    const states = [
        "RYG", "RGY", "RYR", "RGR",
        "YRG", "YGR", "YGY", "YRY",
        "GRY", "GYR", "GRG", "GYG"
    ];
    
    // memo for memoization
    // memo[n][state] stores number of ways for `n` rows with previous row state
    let memo = Array.from({ length: n }, () => Array(12).fill(-1));
    
    const solveRec = (rows, pr) => {
        // base case - if no row left to paint
        // then count 1 valid configuration
        if (rows === 0) return 1;
        
        // return precomputed value
        if (memo[rows][pr] !== -1) {
            return memo[rows][pr];
        }
        
        // recursive case - try all current row states
        let res = 0;
        for (let cr = 0; cr < 12; cr++) {
            const currPattern = states[cr];
            let conflict = false;
            
            // check vertical conflicts
            for (let c = 0; c < 3; c++) {
                if (currPattern.charAt(c) === states[pr].charAt(c)) {
                    conflict = true;
                    break;
                }
            }
            
            // if there's no conflict, compute number of ways
            if (!conflict) {
                res = (res + solveRec(rows - 1, cr)) % MOD;
            }
        }
        
        // memoize and return
        return memo[rows][pr] = res;
    };
    
    // step 1 - try all possible first-row patterns
    let ans = 0;
    for (let i = 0; i < 12; i++) {
        // step 2 - perform computation using recursion
        ans = (ans + solveRec(n - 1, i)) % MOD;
    }
    
    // step 3 - return final answer
    return ans;
};

// const n = 1;

const n = 5000;
console.log(numOfWays(n));
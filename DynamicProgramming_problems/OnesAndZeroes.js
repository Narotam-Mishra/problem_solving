
// Problem link - https://leetcode.com/problems/ones-and-zeroes/?envType=daily-question&envId=2025-11-11

let findMaxForm = function(strs, m, n) {
    const N = strs.length;

    // step 1 - prepare countPairs (zeros, ones)
    const countPairs = new Array(N).fill(0).map(() => [0,0]);

    // iterate on each string of strs
    for(let i=0; i<N; i++){
        let zeros = 0, ones = 0;

        for(const ch of strs[i]){
            if(ch === '0') zeros++;
            else ones++;
        }

        countPairs[i][0] = zeros;
        countPairs[i][1] = ones;
    }

    // step 2 - initialize memo[m][n][i]
    const memo = new Array(m + 1)
      .fill(0)
      .map(() => new Array(n + 1).fill(0)
      .map(() => new Array(N + 1).fill(-1)));

    // step 3 - using solve() as recursive helper function
    const solve = (m, n, i) => {
        // base case:
        if(i >= N || (m === 0 && n === 0)){
            return 0;
        }

        // if answer is already computed then return it
        if(memo[m][n][i] !== -1){
            return memo[m][n][i];
        }

        let take = 0;
        const zeros = countPairs[i][0];
        const ones = countPairs[i][1];

        // option 1 - take option
        if(zeros <= m && ones <= n){
            take = 1 + solve(m - zeros, n - ones, i+1);
        }

        // option 2 - skip option
        const skip = solve(m, n, i+1);

        return memo[m][n][i] = Math.max(take, skip);
    };

    // step 3 - start recursion from index 0
    // compute result and return it
    return solve(m, n, 0);
};

// const strs = ["10","0001","111001","1","0"], m = 5, n = 3;

const strs = ["10","0","1"], m = 1, n = 1;
console.log(findMaxForm(strs, m, n));
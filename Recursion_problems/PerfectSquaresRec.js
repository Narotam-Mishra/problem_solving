
// Problem link - https://leetcode.com/problems/perfect-squares/description/

let sqArr;

function PerfectSquaresRec(num){
    // Base case: if num is 0 return 0
    if(num === 0) return 0;

    let ans = Number.MAX_VALUE;
    let n = sqArr.length;

    // Recursive case f(num) = 1 + min(f(num - sqArr[i]))
    for(let i=0; i<n; i++){
        if(num >= sqArr[i]){
            ans = Math.min(ans, PerfectSquaresRec(num - sqArr[i]));
        }
    }

    return 1 + ans;
}

let numSquares = function(n) {
    sqArr = Array(n+1);
    for(let i=1; i<=n; i++){
        sqArr.push(i*i);
    }
    let res = PerfectSquaresRec(n);
    return res;
};

// let n = 12;

let n = 13;
let res = numSquares(n);
console.log(res);

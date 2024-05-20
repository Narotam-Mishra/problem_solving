
// Problem link - https://leetcode.com/problems/fibonacci-number/description/

let fib = function(n) {
    if(n === 0 || n === 1) return n;
    else{
        return fib(n-1) + fib(n-2);
    }
};

let ans = fib(7);
console.log(ans);
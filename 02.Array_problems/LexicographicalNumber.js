
// Problem link - https://leetcode.com/problems/lexicographical-numbers/description/

// Approach - Brute Force
let lexicalOrder1 = function(n) {
    let res = [];
    for(let i=1; i<=n; i++){
        let strNum = i.toString();
        res.push(strNum);
    }
    res.sort();
    return res;
};

// Approach - using Recursion

function getLexicographicalOrderRecursion(curNum, num, res){
    // Base case: if the current number exceeds n, return
    if(curNum > num) return;

    // add current number curNum to result array res
    res.push(curNum);

    // Recursively call the recursive function for next numbers in lexical order (by multiplying by 10)
    getLexicographicalOrderRecursion(curNum * 10, num, res);

    //check if the last digit of the current number is not 9, recursively call for the next number
    if(curNum % 10 !== 9) getLexicographicalOrderRecursion(curNum + 1, num, res);
}

let lexicalOrder = function(n) {
    let res = [];
    getLexicographicalOrderRecursion(1, n, res);
    return res;
};


let n = 100;
let ans = lexicalOrder(n);
console.log(...ans);
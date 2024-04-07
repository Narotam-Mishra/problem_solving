
// Problem link - https://leetcode.com/problems/lexicographical-numbers/description/

let lexicalOrder = function(n) {
    let res = [];
    for(let i=1; i<=n; i++){
        let strNum = i.toString();
        res.push(strNum);
    }
    res.sort();
    return res;
};

let n = 100;
let ans = lexicalOrder(n);
console.log(...ans);
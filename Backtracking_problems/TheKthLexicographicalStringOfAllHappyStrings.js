
// Problem link - https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2026-03-14

let getHappyString = function(n, k) {
    const res = [];

    function solveRec(curr) {

        // base case
        if (curr.length === n) {
            res.push(curr);
            return;
        }

        // backtracking
        for (let ch of ['a', 'b', 'c']) {

            // avoid same adjacent characters
            if (curr.length > 0 && curr[curr.length - 1] === ch)
                continue;

            // explore
            solveRec(curr + ch);
        }
    }

    solveRec("");

    if (k > res.length)
        return "";

    return res[k - 1];
}

const n = 3, k = 9;
console.log(getHappyString(n, k));

// Problem link - https://leetcode.com/problems/count-square-sum-triples/?envType=daily-question&envId=2025-12-08

let countTriples = function (n) {
    // store count of square triplets
    let count = 0;

    // step 1 - iterate on possible value of `a` & `b` and find triplets
    for (let a = 1; a <= n; a++) {
        for (let b = 1; b <= n; b++) {
            // compute `c2`
            let c2 = a * a + b * b;

            // find square root value of `c2`
            let c = Math.round(Math.sqrt(c2));

            // check if `c2` is perfect square number or not
            if (c <= n && c * c == c2) {
                // increment triplet counter
                count++;
            }
        }
    }

    // step 3 - return the number of square triples
    return count;
};

// const n = 5;

const n = 10;
console.log(countTriples(n));
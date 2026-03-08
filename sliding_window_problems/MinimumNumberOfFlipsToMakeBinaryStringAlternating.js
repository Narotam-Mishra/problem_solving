
// Problem link - https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/

let minFlips = function (s) {
    const n = s.length;

    // store final result in `res`
    let res = Infinity;

    // keep track of flip required for both string s1 & s2
    let f1 = 0, f2 = 0;

    // step 1 - using sliding window approach
    let i = 0, j = 0;
    // expand window
    while (j < 2 * n) {
            // step 2 - find expected character for string s1 & s2
            let expCharS1 = (j % 2 == 1) ? '1' : '0';
            let expCharS2 = (j % 2 == 1) ? '0' : '1';

        // check for mismatch with pattern `s1`
        if (s.charAt(j % n) != expCharS1) {
            f1++;
        }

        // check for mismatch with pattern `s2`
        if (s.charAt(j % n) != expCharS2) {
            f2++;
        }

        // step 3 - check if window size exceed `n`
        // then shrink the window
        if (j - i + 1 > n) {
            expCharS1 = (i % 2 == 1) ? '1' : '0';
            expCharS2 = (i % 2 == 1) ? '0' : '1';

            // remove the effect of character leaving the window
            if (s.charAt(i % n) != expCharS1) {
                f1--;
            }

            if (s.charAt(i % n) != expCharS2) {
                f2--;
            }

            // move left poleter
            i++;
        }

        // step 4 - when window size is exactly n
        if (j - i + 1 == n) {
            // then update final result, `res`
            res = Math.min(res, Math.min(f1, f2));
        }

        // step 5 - move right poleter to expand window
        j++;
    }

    // step 6 - return final result, `res`
    return res;
};

const s = "111000";
console.log(minFlips(s));

// Problem link - https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/?envType=daily-question&envId=2026-02-23

let hasAllCodes = function (s, k) {
    let n = s.length;

    // store unique codes of k length
    const seen = new Set();

    // step 1 - iterate on binary string
    let codes = (1 << k);
    for (let i = k; i <= n; i++) {
        // step 2 - find code of length k
        let sub = s.substr(i - k, k);

        // step 3 - check in set
        if (!seen.has(sub)) {
            seen.add(sub);
            codes--;
        }

        // step 4 - check all codes has been check
        if (codes == 0) {
            // then return true immediately
            return true;
        }
    }

    // step 5 - otherwise return false
    return false;
};

// const s = "00110110", k = 2;

// const s = "0110", k = 1;

const s = "0110", k = 2;
console.log(hasAllCodes(s,k));
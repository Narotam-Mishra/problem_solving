
// Problem link - https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-03-08

let findDifferentBinaryString = function (nums) {
    let n = nums.length;

    // keep track of resultant string, `res`
    let res = "";

    // step 1 - iterate through each position i from 0 to n-1
    for (let i = 0; i < n; i++) {
        // step 2 - extract the character at diagonal position [i][i]
        const ch = nums[i].charAt(i);

        // step 3 - flip the bit (0 becomes 1, 1 becomes 0)
        // this guarantees the result differs from every input string
        if (ch == '0') {
            res += "1";
        } else {
            res += "0";
        }
    }

    // step 4 - return the constructed unique binary string
    return res;
};
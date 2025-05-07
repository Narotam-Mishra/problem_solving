
// Problem link - https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/?envType=problem-list-v2&envId=string

let minOperations = function(s) {
    // step 1 - initialize counts for two patterns, '010101..' & '10101010..'
    let countAPattern = 0;
    let countBPattern = 0;

    // step 2 - iterate on each character of binary string
    for(let i=0; i<s.length; i++){
        // step 3 - find expected character for both patterns
        const expectedA = i % 2 === 0 ? '0' : '1';
        const expectedB = i % 2 === 0 ? '1' : '0';

        // step 4 - count mismatch for pattern A
        if(s[i] !== expectedA){
            countAPattern++;
        }

        // count mismatch for pattern B
        if(s[i] !== expectedB){
            countBPattern++;
        }
    }

    // step 5 - return the minimum operations needed to convert to either pattern
    return Math.min(countAPattern, countBPattern);
};

const s = "0100";

// const s = "10";

// const s = "1111";

console.log(minOperations(s));

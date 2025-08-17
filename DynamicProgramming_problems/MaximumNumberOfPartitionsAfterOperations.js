
// Problem link - https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/?envType=daily-question&envId=2025-10-17

let maxPartitionsAfterOperations = function(s, k) {
    // memoization map: stores computed results for (index, uniqueChars bitmask, canChange flag)
    const memo = new Map();
    
    // helper function to count set bits in a number
    const bitCount = (n) => {
        let count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    };

    const solveRec = (i, uniqueChars, canChange) => {
        // create unique key combining: index (bits 27+), uniqueChars bitmask (bits 1-26), canChange flag (bit 0)
        const key = (BigInt(i) << 27n) | (BigInt(uniqueChars) << 1n) | BigInt(canChange ? 1 : 0);

        // return cached result if already computed
        if (memo.has(key.toString())) {
            return memo.get(key.toString());
        }

        // base case: reached end of string, no more partitions possible
        if (i >= s.length) {
            return 0;
        }

        // get character index (0-25 for 'a'-'z')
        const charIndex = s.charCodeAt(i) - 97; // 97 is 'a'
        
        // add current character to the bitmask (set corresponding bit)
        const newUniqueChars = uniqueChars | (1 << charIndex);
        
        // count number of distinct characters using bitCount (counts set bits)
        const uniqueCharsCount = bitCount(newUniqueChars);

        let res;
        // if adding current character exceeds K distinct characters
        if (uniqueCharsCount > k) {
            // start a new partition: increment count and reset bitmask to only current character
            res = 1 + solveRec(i + 1, 1 << charIndex, canChange);
        } else {
            // continue current partition: keep the updated bitmask
            res = solveRec(i + 1, newUniqueChars, canChange);
        }

        // if we still have the option to change one character
        if (canChange) {
            // try changing current character to each of 26 possible letters
            for (let newCharId = 0; newCharId < 26; newCharId++) {
                // calculate new bitmask with the changed character
                const newCharSet = uniqueChars | (1 << newCharId);
                const newUniqueCharCount = bitCount(newCharSet);

                // if changing causes partition split
                if (newUniqueCharCount > k) {
                    // start new partition with changed character, mark canChange as false
                    res = Math.max(res, 1 + solveRec(i + 1, 1 << newCharId, false));
                } else {
                    // continue partition with changed character, mark canChange as false
                    res = Math.max(res, solveRec(i + 1, newCharSet, false));
                }
            }
        }

        // cache and return the result
        memo.set(key.toString(), res);
        return res;
    };

    // start with empty bitmask (0), canChange = true
    // add 1 because we count partition boundaries, need to add final partition
    return solveRec(0, 0, true) + 1;
};

// const s = "accca", k = 2;

// const s = "aabaab", k = 3;

const s = "xxyz", k = 1;
console.log(maxPartitionsAfterOperations(s, k));

// Problem link - https://leetcode.com/problems/binary-watch/?envType=daily-question&envId=2026-02-17

let readBinaryWatch = function(turnedOn) {
    const result = [];

    // helper function to count set bits
    const bitCount = (num) => {
        let count = 0;
        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    };

    // step 1 - iterate hours
    for (let h = 0; h < 12; h++) {

        // step 2 - iterate minutes
        for (let m = 0; m < 60; m++) {

            // step 3 - check total set bits
            if (bitCount(h) + bitCount(m) === turnedOn) {

                // step 4 - format time
                const minute = m < 10 ? "0" + m : m.toString();
                result.push(`${h}:${minute}`);
            }
        }
    }

    // step 5 - return final result
    return result;
};

const turnedOn = 2;
console.log(readBinaryWatch(turnedOn));

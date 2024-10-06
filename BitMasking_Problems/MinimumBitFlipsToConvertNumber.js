
// Problem link : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

let minBitFlips = function(start, goal) {
    // XOR the two numbers. The result will have bits set to 1 where x and y have different bits.
    let xor = start ^ goal;

    // initialize a counter to keep track of the number of different bits
    let dist = 0;

    // loop through all bits in the XOR result
    while(xor > 0){
        // increment the counter if the least significant bit is 1
        dist += xor & 1;

        // right shift the XOR result by 1 to check the next bit.
        xor = xor >> 1;
    }

    // return the total count of different bits.
    return dist;
};

// let start = 10, goal = 7;

let start = 3, goal = 4;
console.log(minBitFlips(start, goal));

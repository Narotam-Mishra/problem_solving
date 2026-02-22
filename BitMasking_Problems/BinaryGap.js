
// Problem link : https://leetcode.com/problems/binary-gap/description/?envType=problem-list-v2&envId=bit-manipulation

let binaryGap1 = function(n) {
    let maxDistance = 0;
    let lastPos = -1;
    let currPos = 0;

    while(n > 0){
        // check if the current bit is 1
        if(n & 1){
            if(lastPos !== -1){
                // calculate the distance between the current and last 1
                maxDistance = Math.max(maxDistance, currPos - lastPos);
            }
            // update the position of the last 1
            lastPos = currPos
        }
        // shift right to process the next bit
        n = n >> 1;
        // update current position 'currPos'
        currPos++;
    }

    return maxDistance;
};

let binaryGap = function(n) {
    // keep track of longest distance
    let maxDistance = 0;

    // keep track of previous 1's position
    let lastPos = -1;

    // step 1 - iterate on 32-bits of input number
    for(let cp=0; cp<32; cp++){
        // step 2 - check if the current bit is 1
        if(((n >> cp) & 1) > 0){
            if(lastPos !== -1){
                // step 3 - calculate the distance between the current and last 1
                maxDistance = Math.max(maxDistance, cp - lastPos);
            }

            // update the position of the last 1
            lastPos = cp;
        }
    }

    // step 4 - return longest distance
    return maxDistance;
};

let num = 22;

// let num = 8;

// let num = 5;
console.log(binaryGap(num));

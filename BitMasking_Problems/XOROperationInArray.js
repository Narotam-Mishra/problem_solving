
// Problem link : https://leetcode.com/problems/xor-operation-in-an-array/?envType=problem-list-v2&envId=bit-manipulation

let xorOperation1 = function(n, start) {
    let xorVal = 0;
    let nums = new Array(n);

    // form array with given condition
    for(let i=0; i<n; i++){
        nums[i] = start + 2 * i;
        // calculate running XOR value
        xorVal ^= nums[i];
    }
    // return XOR value 'xorVal'
    return xorVal;
};

let xorOperation = function(n, start) {
    let xorVal = 0;
    
    for(let i=0; i<n; i++){
        // calculate running XOR value
        xorVal ^= start + 2 * i;
    }
    // return XOR value 'xorVal'
    return xorVal;
};

// let n = 5, start = 0;

let n = 4, start = 3;
console.log(xorOperation(n, start));


// Problem link : https://leetcode.com/problems/counting-bits/description/

let countBits = function(n) {
    let ansArr = new Array(n+1).fill(0);

    // loop through all numbers from 0 to n
    for(let i=0; i<=n; i++){
        let num = i;

        // reset setBits counter for each number
        let setBits = 0;

        // count the number of 1's in the binary representation of num
        while(num > 0){
            // increment if the least significant bit is 1
            setBits += num & 1;
            // right shift num by 1 bit
            num = num >> 1;
        }

        // store the result in the correct index
        ansArr[i] = setBits;
    }
    return ansArr;
};

let num = 5;
let res = countBits(num);
console.log(res);

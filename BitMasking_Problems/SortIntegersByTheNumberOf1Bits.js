
// Problem link : https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/?envType=problem-list-v2&envId=bit-manipulation

function countSetBits(num){
    let count = 0;
    while(num > 0){
        count += num & 1;
        num = num >> 1
    }
    return count;
}

let sortByBits = function(arr) {
    arr.sort((a,b) => {
        let countA = countSetBits(a);
        let countB = countSetBits(b);

        // sort by value when the number of bits is the same
        if(countA === countB){
            return a - b;
        }else{
            // sort by the number of set bits
            return countA - countB;
        }
    })
    return arr;
};

// let nums = [0,1,2,3,4,5,6,7,8];

let nums = [1024,512,256,128,64,32,16,8,4,2,1];
console.log(sortByBits(nums));

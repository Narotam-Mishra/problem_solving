
// Problem link : https://leetcode.com/problems/find-lucky-integer-in-an-array/description/?envType=problem-list-v2&envId=hash-table

// utlity function to check if number is lucky or not
function isLuckyNum(num, count){
    return num === count;
}

let findLucky = function(arr) {
    // step 1 - create frequency map array to store frquency of each number from array
    const freqArr = new Array(501).fill(0);
    for(let num of arr){
        freqArr[num]++;
    }

    // step 2 - iterate frquency array return largest Lucky number
    for(let i=freqArr.length-1; i>0; i--){
        if(isLuckyNum(i, freqArr[i])){
            return freqArr[i];
        }
    }

    // step 3 - otherwise return -1
    return -1;
};

// const arr = [2,2,3,4];

// const arr = [1,2,2,3,3,3];

const arr = [2,2,2,3,3];
console.log(findLucky(arr));

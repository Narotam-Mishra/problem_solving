
// Problem link - https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description/?envType=problem-list-v2&envId=array

// utility function to find sum of digits of a number
function findDigitsSum(num){
    let sum = 0;
    while(num > 0){
        sum += num % 10;
        num = Math.floor(num/10);
    }
    return sum;
}

let minElement = function(nums) {
    // store minimum number after replacement in `minNum`
    let minNum = Infinity;

    // step 1 - iterate on `nums` array
    for(let num of nums){
        // step 2 - find digit sum if it is grater than 9
        if(num > 9){
            let s = findDigitsSum(num);
            // step 3 - update minimum number
            minNum = Math.min(minNum, s);
        }else{
            // update minimum number
            minNum = Math.min(minNum, num);
        }
    }

    // step 4 - return minimum number `minNum` after replacement
    return minNum;
};

// const nums = [1, 2, 3, 4];

// const nums = [10,12,13,14];

const nums = [999,19,199];
console.log(minElement(nums));
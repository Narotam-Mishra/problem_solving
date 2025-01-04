
// Problem link : https://leetcode.com/problems/sum-of-unique-elements/description/?envType=problem-list-v2&envId=hash-table

let sumOfUnique1 = function(nums) {
    let sum = 0;

    let map = new Map();
    nums.forEach((num) => {
        map.set(num, (map.get(num) || 0) + 1);
    });

    map.forEach((value, key) => {
        if (value === 1) {
            sum += key;
        }
    });
    return sum;
};

let sumOfUnique = function(nums) {
    // step 1 - intialize `sum` variable to store unique numbers sum
    let sum = 0;

    // step 2 - create frequency array to count frequency
    const frqArr = new Array(101).fill(0);

    // fill frequency
    for(let num of nums){
        frqArr[num]++;
    }

    // step 3 - iterate over frequency array and add unique numbers to sum
    for(let i=1; i<frqArr.length; i++){
        if(frqArr[i] === 1){
            sum += i;
        }
    }

    // step 4 - return unique numbers sum
    return sum;
};

// const nums = [1, 2, 3, 2];

// const nums = [1,1,1,1,1];

const nums = [1, 2, 3, 4, 5]
console.log(sumOfUnique(nums)); // 4

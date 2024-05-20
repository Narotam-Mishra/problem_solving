
// Problem link - https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/

// Approach - 1 (using frequency array)

let minimumOperations = function(nums) {
    let table = Array(101).fill(0);

    // add frequency of each non-zero numbers in frequency table
    for(let num of nums){
        table[num] += 1;
    }

    // the minimum number of operations to make every element in nums equal to 0.
    // is number of unique non-zero numbers in nums array
    let ans = 0;
    for(let i=1; i<101; i++){
        if(table[i] > 0){
            ans += 1;
        }
    }
    return ans;
};

let arr = [1,5,0,3,5];
console.log(minimumOperations(arr));

// Approach - 2 (using Set)

let minimumOperations1 = function(nums) {
    let s = new Set();
    for(let num of nums){
        if(num>0){
            s.add(num)
        }
    }
    return s.size;
};

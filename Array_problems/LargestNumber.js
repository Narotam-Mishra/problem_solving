
// Problem link : https://leetcode.com/problems/largest-number/

let largestNumber = function(nums) {
    // custom comparison function to determine the order of concatenation
    const customeCompare = (a, b) => {
        // concate a + b
        const order1 = `${a}${b}`;

        // concate b + a
        const order2 = `${b}${a}`;

        // sort in ascending order
        return order2 - order1;
    };

    // sort the numbers using the custom comparison function
    nums.sort(customeCompare);

    // if the largest number is 0, return "0" to avoid leading zeros
    if(nums[0] === 0){
        return "0";
    }

    // concatenate the sorted numbers to form the largest number
    return nums.join("");
};

const nums = [3, 30, 34, 5, 9];
console.log(largestNumber(nums));
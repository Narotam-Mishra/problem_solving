
// Problem link - https://leetcode.com/problems/range-sum-query-immutable/description/

let NumArray = function(nums) {
    this.nums = nums;
};

/** 
 * @param {number} left 
 * @param {number} right
 * @return {number}
 */
NumArray.prototype.sumRange = function(left, right) {
    let sum = 0;
    for(let i=left; i<=right; i++){
        sum += this.nums[i];
    }
    return sum
};

// Main method
function main() {
    // Example usage
    let nums = [1, 2, 3, 4, 5];
    let numArray = new NumArray(nums);
    
    // Test the sumRange method
    console.log(numArray.sumRange(0, 2)); // Output: 6 (1 + 2 + 3)
    console.log(numArray.sumRange(1, 3)); // Output: 9 (2 + 3 + 4)
    console.log(numArray.sumRange(2, 4)); // Output: 12 (3 + 4 + 5)
}

// Call the main method
main();
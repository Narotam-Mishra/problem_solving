
// Problem link - https://leetcode.com/problems/largest-perimeter-triangle/description/

let largestPerimeter = function(nums) {
    
    //step 1: sort the numbers array in descending order
    nums.sort((a,b) => b - a);

    // Step 2: Iterate through the array and check for valid triangles
    for(let i=0; i<nums.length-2; i++){
        // Pick three consecutive elements
        let a = nums[i];
        let b = nums[i+1];
        let c = nums[i+2];

        // Step 3: Check the triangle inequality theorem
        if(a < b + c){
            return a + b + c;
        }
    }

    // Step 4: If no valid triangle is found, return 0
    return 0;
};

let nums = [1,2,1,10];
console.log(largestPerimeter(nums));
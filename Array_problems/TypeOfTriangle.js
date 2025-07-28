
// Problem link - https://leetcode.com/problems/type-of-triangle/description/?envType=problem-list-v2&envId=array

let triangleType = function(nums) {
    // step 1 - extract three sides from `nums` array
    const [a, b, c] = nums;

    // step 2 - check condition for valid traingle
    if(a + b <= c || b + c <= a || c + a <= b){
        // return as it is invalid case for triangle
        return "none";
    }

    // step 3 - check condition for each type of triangle and return its type
    if(a === b && b === c){
        return "equilateral";
    }else if(a === b || b === c || c === a){
        return "isosceles";
    }else{
        return "scalene";
    }
};

// const nums = [3,3,3];

const nums = [3,4,5];
console.log(triangleType(nums));
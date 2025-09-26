
// Problem link - https://leetcode.com/problems/valid-triangle-number/description/?envType=daily-question&envId=2025-09-26

let triangleNumber = function(nums) {
    // step 1 - sort the array
    nums.sort((a,b) => a - b);

    // store the number of triplets that can form triangle
    let count = 0;
    const n = nums.length;

    // step 2 - fix the largest side and find pairs for the other two sides
    // we iterate from the end because after sorting, the largest element
    // will be at the end, and we want to fix it as the longest side
    for(let k=n-1; k>=2; k--){
        // step 3 - using two pointers
        // left pointer starts from beginning, right from k-1
        let s = 0;
        let e = k-1;

        // Triangle inequality: For three sides a, b, c (where c is largest)
        // a + b > c is the only condition we need to check
        // (since a + c > b and b + c > a are automatically satisfied when c is largest)
        while(s < e){
            // step 4 - check if current triplet forms a valid triangle
            if(nums[s] + nums[e] > nums[k]){
                // if nums[s] + nums[e] > nums[k], then all pairs
                // (s, s+1), (s, s+2), ..., (s, e)
                // will also satisfy the condition with nums[k] as nums is sorted
                count += (e - s);

                // move right pointer leftward
                e--;
            }else{
                // if sum is not greater than nums[k], we need a larger sum
                // so move left pointer rightward to get larger values
                s++;
            }
        }
    }

    // step 5 - return final count
    return count;
};

// const nums = [2,2,3,4];

const nums = [4,2,3,4];
console.log(triangleNumber(nums));
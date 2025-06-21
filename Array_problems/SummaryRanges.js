
// Problem link - https://leetcode.com/problems/summary-ranges/description/?envType=problem-list-v2&envId=array

let summaryRanges = function(nums) {
    // store result in `res` array
    const res = [];
    const n = nums.length;

    // edge case:
    if(n === 0) return res;

    // step 1 - start current range
    let start = nums[0];

    // step 2 - iterate through the array
    for(let i=1; i<n; i++){
        // step 3 - if current number is not consecutive
        if(nums[i] !== nums[i-1] + 1){
            // step 4 - end the current range and add to result
            if(start === nums[i-1]){
                // add single number
                res.push(start.toString());
            }else{
                // add range
                res.push(`${start}->${nums[i-1]}`);
            }

            // step 5 - start new range from current number
            start = nums[i];
        }
    }

    // step 6 - handle last range after loop
    if(start === nums[n - 1]){
        // add single number
        res.push(start.toString())
    }else{
        // add range
        res.push(`${start}->${nums[n-1]}`);
    }

    // step 7 - return result `res`
    return res;
};

const nums = [0,1,2,4,5,7];
console.log(summaryRanges(nums));

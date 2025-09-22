
// Problem link - https://leetcode.com/problems/find-the-array-concatenation-value/?envType=problem-list-v2&envId=array

let findTheArrayConcVal = function(nums) {
    const n = nums.length;
    // store final result in `res`
    let res = 0;

    // step 1 - use two-pointers to point start and end of `nums`
    let s = 0, e = n - 1;

    // step 2 - iterate on nums using two-pointers
    while(s < e){
        // step 3 - concate first and last value from nums
        let concatVal = nums[s].toString() + nums[e].toString();
        
        // step 4 - add it to final result `res`
        res += Number(concatVal);

        // step 5 - update both pointers
        s++;
        e--;
    }

    // step 6 - if size of `nums` is odd 
    // then add one remaining element in result `res`
    if(n % 2 === 1){
        res += nums[s];
    }

    // step 7 - return final `res`
    return res;
};

const nums = [7,52,2,4];

// const nums = [5,14,13,8,12];
console.log(findTheArrayConcVal(nums));
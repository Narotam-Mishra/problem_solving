
// Problem link - https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/description/?envType=problem-list-v2&envId=array

let minimumAverage = function(nums) {
    // find length of `nums` array
    const n = nums.length;

    // store minimum average in `minAvg`
    let minAvg = Infinity;

    // step 1 - sort `nums` for easy iteration using two pointers
    nums.sort((a,b) => a-b);
    
    // step 2 - rpeat operation n/2 times
    let s = 0, e = n-1;
    while(s < e){
        // step 3 - calculate current average `currAvg`
        let currAvg = (nums[s] + nums[e])/2;

        // step 4 - update minimum average `minAvg`
        minAvg = Math.min(currAvg, minAvg);

        // move start `s` and end `e` pointer
        s++;
        e--;
    }

    // step 5 - return minimum running average
    return minAvg
};

const nums = [7,8,3,4,15,13,4,1];

// const nums = [1,9,8,3,10,5];

// const nums = [1,2,3,7,8,9];
console.log(minimumAverage(nums));
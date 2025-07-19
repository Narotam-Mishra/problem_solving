
// Problem link - https://leetcode.com/problems/minimum-number-game/description/?envType=problem-list-v2&envId=array

let numberGame = function(nums) {
    // store result in `res`
    const res = [];

    // step 1 - sort the array to get minimum number easily
    nums.sort((a,b) => a-b);

    // step 2 - iterate on `nums` array
    const n = nums.length;
    for(let i=0; i<n; i+=2){
        // step 3 - get minimum element for Alicer and Bob
        let minAlice = nums[i];
        let minBob = nums[i+1];

        // step 4 - store minimum element as per given condition
        res.push(minBob);
        res.push(minAlice);
    }

    // step 5 - return result `res`
    return res;
};

// const nums = [5,4,2,3];

const nums = [2,5];
console.log(numberGame(nums));
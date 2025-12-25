
// Problem link - https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2025-12-25

let maximumHappinessSum = function(happiness, k) {
    // store final result in `res`
    let res = 0;

    // step 1 - sort happiness in descending order
    // since we have to maximise the result
    happiness.sort((a,b) => b - a);

    // step 2 - keep track of number of child picked in `count` till now
    let count = 0;
    for(let i=0; i<k; i++){
        // step 3 - calculate maximum possible happiness value
        res += Math.max(0, happiness[i] - count);

        // increment count as we have picked this child
        count++;
    }

    // step 4 - return the maximum sum of the happiness values from `res`
    return res;
};

// const happiness = [1,2,3], k = 2;

// const happiness = [1,1,1,1], k = 2;

const happiness = [2,3,4,5], k = 1;
console.log(maximumHappinessSum(happiness, k));
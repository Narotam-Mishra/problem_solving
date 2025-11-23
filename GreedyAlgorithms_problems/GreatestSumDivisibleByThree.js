
let maxSumDivThree = function(nums) {
    // step 1 - categorize numbers by their remainder when divided by 3
    const remain1 = [];  
    const remain2 = [];

    // calculate the total sum of all elements
    let sum = 0;
    for(const num of nums){
        sum += num;

        // categorize based on remainder
        if(num % 3 === 1){
            remain1.push(num);
        } else if(num % 3 === 2){
            remain2.push(num);
        }
    }

    // edge case: If the total sum is already divisible by 3,
    if(sum % 3 === 0){
        return sum;
    }

    // step 2 - sort both arrays in ascending order
    remain1.sort((a, b) => a - b);
    remain2.sort((a, b) => a - b);

    // step 3 - based on the remainder of total sum, decide what to remove
    let res = 0;
    const remainder = sum % 3;
    
    if(remainder === 1){
        // total sum has remainder 1
        // option 1: Remove one smallest number with remainder 1
        const r1 = remain1.length >= 1 ? remain1[0] : Infinity;
        
        // option 2: Remove two smallest numbers with remainder 2
        const r2 = remain2.length >= 2 ? remain2[0] + remain2[1] : Infinity;

        // choose the option that removes the minimum value (maximizes result)
        res = Math.max(res, sum - Math.min(r1, r2));
    }
    else{ // remainder === 2
        // total sum has remainder 2
        // option 1: Remove one smallest number with remainder 2
        const r1 = remain2.length >= 1 ? remain2[0] : Infinity;
        
        // option 2: Remove two smallest numbers with remainder 1
        const r2 = remain1.length >= 2 ? remain1[0] + remain1[1] : Infinity;

        // Choose the option that removes the minimum value (maximizes result)
        res = Math.max(res, sum - Math.min(r1, r2));
    }

    // step 4 - return final result, `res`
    return res;
};

// const nums = [3,6,5,1,8];

// const nums = [1,2,3,4,4];

const nums = [4];
console.log(maxSumDivThree(nums));
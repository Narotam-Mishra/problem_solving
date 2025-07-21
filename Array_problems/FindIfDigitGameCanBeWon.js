
// Problem link - https://leetcode.com/problems/find-if-digit-game-can-be-won/description/?envType=problem-list-v2&envId=array

let canAliceWin = function(nums) {
    // store single digit and double digits sum
    let sdSum = 0, ddSum = 0; 

    // step 1 - iterate on each number of `nums`
    for(let num of nums){
        if(num < 10){
            // find single digit number sum
            sdSum += num;
        }else{
            // find doubel digit number sum
            ddSum += num;
        }
    }

    // step 2 - Alice wins if the sums are different (she picks the larger one)
    return sdSum !== ddSum;
};

// const nums = [1,2,3,4,10];

// const nums = [1,2,3,4,5,14];

const nums = [5,5,5,25];
console.log(canAliceWin(nums));
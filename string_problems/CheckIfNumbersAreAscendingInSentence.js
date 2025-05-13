
// Problem link - https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/?envType=problem-list-v2&envId=string

// Approach - 1 (Brute Force)
let areNumbersAscending1 = function(s) {
    const tokens = s.split(' ');
    const nums = [];

    for(let token of tokens){
        if(isNaN(token)){
            continue;
        }else{
            let num = Number(token);
            nums.push(num);
        }
    }

    for(let i=1; i<nums.length; i++){
        if(nums[i-1] >= nums[i]){
            return false;
        }
    }
    return true;
};

let areNumbersAscending = function(s) {
    // step 1 - split string tokens into array 
    const tokens = s.split(' ');
    let prevNum = -Infinity;

    // step 2 - iterate on each token of `s` and filter number
    for(const token of tokens){
        // step 3 - filter number token
        if(/^[1-9][0-9]*$/.test(token)){
            let currNum = parseInt(token, 10);

            // step 4 - check if current number is less previous number
            if(currNum <= prevNum){
                // immdeiately return false because not in increasing sequence anymore
                return false;
            }

            // update previous number
            prevNum = currNum;
        }
    }

    // step 5 - return true if loop is completed
    return true;
};

const s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles";

// const s = "hello world 5 x 5";

// const s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s";
console.log(areNumbersAscending(s));
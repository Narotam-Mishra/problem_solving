
// Problem link - https://leetcode.com/problems/sort-array-by-parity/?envType=problem-list-v2&envId=two-pointers

let sortArrayByParity = function(nums) {
    // using two-pointer approach
    let s = 0, e = nums.length-1;

    // utility function to swap
    function swap(i , j){
        let temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // step 1 - iterate through array using two-pointers
    while(s < e){
        // step 2 - if left element is odd and right element is even, swap them
        if(nums[s] % 2 === 1 && nums[e] % 2 === 0){
            // perform swap
            swap(s, e);
            s++;
            e--;
        }
        // step 3 - if left element is even, move left pointer
        else if(nums[s] % 2 === 0){  
            s++;
        }
        // step 4 - otherwise, if right element is odd, move right pointer
        else{
            e--;
        }
    }

    // step 5 - return array after operation completed
    return nums;
};

const nums = [3,1,2,4];

// const nums = [0];
console.log(sortArrayByParity(nums));
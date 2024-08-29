
// Problem link : https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-100-liked

let majorityElement1 = function(nums) {
    let objMap = {};
    let maxSize = Math.floor(nums.length / 2);

    for(let num of nums){
        if(objMap[num]){
            objMap[num]++;
        }else{
            objMap[num] = 1;
        }
    }

    for(key in objMap){
        if(objMap[key] > maxSize){
            return key;
        }
    }

    return -1;
};

let majorityElement = function(nums) {
    let reqNum = nums[0];
    let count = 1;

    for(let i=1; i<nums.length; i++){
        if(reqNum === nums[i]){
            count++;
        }else{
            count--;
            if(count === 0){
                reqNum = nums[i];
                count = 1;
            }
        }
    }
    return reqNum;
};

let arr = [2,2,1,1,1,2,2];
console.log(majorityElement(arr));


// Problem link - https://leetcode.com/problems/single-element-in-a-sorted-array/description/

// Approach - 1 (using Binary search)

/*

if the mid index is at an even position and both elements(mid and mid+1) are the same, we move to the right half of the array. If the pair is not intact(not same), we move to the left half of the array. 

*/
let singleNonDuplicate = function(nums) {
    let s = 0, e = nums.length-1;

    while(s <= e){
        let mid = s + Math.floor((e - s)/2);

        if(mid%2 == 1){
            mid--;
        }

        // if pair is intact (i.e mid and mid+1 th elements are same)
        // discard left half
        if(nums[mid] === nums[mid+1]){
            s = mid + 2;
        }else {
            // otherwise discard right half
            e = mid - 1;
        }
    }
    // At this point, start,s and end,e converge to the single element
    return nums[s];
};

let arr = [1,1,2,3,3,4,4,8,8];
let ans = singleNonDuplicate(arr);
console.log(ans);

// Approach - 2 (using Object as Map)

let singleNonDuplicate1 = function(arr){
    let obMap = {};

    for(let i=0; i<arr.length; i++){
        if(obMap[arr[i]]){
            // if array's element exist in map then increment its frequency
            obMap[arr[i]]++;
        }else{
            // otherwise set frequency of array's element
            obMap[arr[i]] = 1;
        }
    }

    for(const k in obMap){
        if(obMap[k] === 1){
            return k;
        }
    }
}

// Approach - 3 (using XOR)

let singleNonDuplicate2 = function(nums) {
    let ans = 0;
    for(let i=0; i<nums.length; i++){
        ans = ans ^ nums[i];
    }
    return ans;
};

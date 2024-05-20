
// Problem link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

let findMin = function(nums) {
    // edge cases
    if(nums.length === 1) return nums[0];
    else if(nums.length == 2){
        if(nums[0] > nums[1]){
            return nums[1];
        }else{
            nums[0];
        }
    }
    let s = 0, e = nums.length - 1;
    let ans = Number.MAX_VALUE;
    while(s <= e){
        let mid = s + Math.floor((e - s)/2);
        // identify the sorted half
        if(nums[s] <= nums[mid]){
            // let us assume the first element in sorted half is minimum ans
            ans = Math.min(ans, nums[s]);
            // discard left half of array
            s = mid + 1;
        }else{
            // otherwise right half is sorted
            ans = Math.min(ans, nums[mid])
            // discard right half of array
            e = mid - 1;
        }
    }
    return ans;
};

let arr = [3,4,5,1,2];
let ans = findMin(arr);
console.log(ans);
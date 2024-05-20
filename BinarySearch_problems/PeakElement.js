
// Problem link - https://leetcode.com/problems/find-peak-element/description/

let findPeakElement = function(nums) {
    if(nums.length === 1) return 0;
    else if(nums[0] > nums[1]) return 0;
    else if(nums[nums.length -1] > nums[nums.length - 2]) return nums.length - 1;

    else{
        let l = 1, r = nums.length - 2;
        while (l <= r){
            let mid = Math.floor((l + r)/2);
            // check mid for peak element
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
                return mid;
                // discard right half of array
            }else if(nums[mid] > nums[mid + 1]){
                r = mid - 1;
            }
            else{
                // discard left half of array
                l = mid + 1;
            }
        }
    }
    return -1;
};
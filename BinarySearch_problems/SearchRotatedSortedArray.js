
// Problem link - https://leetcode.com/problems/search-in-rotated-sorted-array/description/

let search = function(nums, target) {
    let lo = 0, hi = nums.length - 1;

    while(lo <= hi){
        let mid = lo + Math.floor((hi - lo)/2);

        if(nums[mid] === target) return mid;

        //identify the sorted half and discard unsorted half of array
        // left half is sorted, perform BS in left half
        if(nums[lo] <= nums[mid]){
            // check if target is in between lo to mid
            if(nums[lo] <= target && target <= nums[mid]){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        // right half is sorted, perform BS in rightt half
        }else{
            // check if target is in between mid to hi
            if(nums[mid] <= target && target <= nums[hi]){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
    }
    return -1;
};

// Problem link - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

let search = function(nums, target) {
    let low = 0, high = nums.length-1;

    while(low <= high){
        let mid = low + Math.floor((high - low)/2);
        if(nums[mid] === target) return true;

        // if duplicates numbers exist 
        if(nums[low] === nums[mid] && nums[mid] === nums[high]){
            low++;
            high--;
            continue;
        }

        // identify the sorted half of array
        // and perform BS on it
        if(nums[low] <= nums[mid]){
            if(nums[low] <= target && target <= nums[mid]){
                // discard right half of array
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(nums[mid] <= target && target <= nums[high]){
                // discard left half of array
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return false;
};
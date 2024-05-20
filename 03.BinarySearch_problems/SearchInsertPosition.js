
// Problem link - https://leetcode.com/problems/search-insert-position/description/

// Approach - 1 using lowerBound
// TC - O(logN)

function findLowerBound(arr, x){
    let s = 0, e = arr.length-1;
    let ans = arr.length;

    while(s <= e){
        let mid = s + Math.floor((e-s)/2);
        if(x > arr[mid]){
            s = mid + 1
        }else{
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}

let searchInsert = function(nums, target) {
    let lb = findLowerBound(nums, target);
    return lb;
};
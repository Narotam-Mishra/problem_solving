
// Problem link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

function findLowerBound(arr, x){
    let s = 0, e = arr.length - 1;
    let ans = arr.length;

    while(s <= e){
        let mid = s + Math.floor((e - s)/2);
        if(arr[mid] < x){
            // discard left half
            s = mid+1;
        }else{
            // got first probable ans
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}

function findUpperBound(arr, x){
    let s = 0, e = arr.length - 1;
    let ans = arr.length;

    while(s <= e){
        let mid = s + Math.floor((e - s)/2);
        if(arr[mid] <= x){
            // discard left half
            s = mid+1;
        }else{
            // got first probable ans
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}

let searchRange = function(nums, target) {
    let lb = findLowerBound(nums, target);
    if(lb === nums.length || nums[lb] !== target){
        return [-1, -1];
    }
    let ub = findUpperBound(nums,target);
    return [lb,ub-1];
};
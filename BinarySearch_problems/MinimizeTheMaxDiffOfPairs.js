
// Problem link - https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

function canFormAtLeastPpairsWithAtmostMidDifference(arr, mid, p){
    let i = 0, count = 0;
    while(i < arr.length - 1){
        if(arr[i+1] - arr[i] <= mid){
            // whether the diff is atmost mid
            count++;
            i += 2
        }else{
            i++;
        }
    }
    return count >= p;
}

let minimizeMax = function(nums, p) {
    // sort the array
    nums.sort((a,b) => a - b);

    // for search space minimum value, low is 0 and maximum value, high is maximum - minimum value in nums array
    let low = 0, high = nums[nums.length-1] - nums[0];
    let ans = -1

    while(low <= high){
        let mid = low + Math.floor((high - low)/2);
        // check if we can form atleast p pairs with at most mid difference
        if(canFormAtLeastPpairsWithAtmostMidDifference(nums, mid, p)){
            // found first probable answer, ans
            ans = mid;
            // since difference amongst all the pairs is minimized
            // hence discard the right half of search space
            high = mid - 1;
        }else{
            // otherwise discard left half of search space
            low = mid + 1;
        }
    }
    return ans;
}

// let arr = [10,1,2,7,1,3];
// let p = 2;

let arr = [4,2,1,2];
let p = 0;
let ans = minimizeMax(arr, p);
console.log(ans);
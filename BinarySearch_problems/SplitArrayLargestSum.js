
// Problem link - https://leetcode.com/problems/split-array-largest-sum/description/

function isBestWayToSplitArrayWithMidSubArray(arr, mid, k){
    let subArrCount = 0, subArrCurrSum = 0;
    for(let i=0; i<arr.length; i++){
        // if sub array running sum is greater than mid
        // increment the subArray counter, sc
        if(subArrCurrSum + arr[i] > mid){
            subArrCount++;
            subArrCurrSum = 0;
        }
        subArrCurrSum += arr[i];
    }
    // increment sub array counter, subArrCount for last running subArray sum, subArrCurrSum
    subArrCount++;
    return subArrCount <= k;
}

let splitArray = function(nums, k) {
    let maxNum = -1, totalSum = 0;

    for (let num of nums){
        maxNum = Math.max(maxNum, num);
        totalSum  += num;
    }

    // since we have to find the minimized largest sum of the split
    // hence the search space will be from low = maxNum (maximum number in array) to high = totalSum (total sum of array)
    let low = maxNum, high = totalSum;
    let ans = -1
    while(low <= high){
        let mid = low + Math.floor((high - low)/2);
        if(isBestWayToSplitArrayWithMidSubArray(nums, mid, k)){
            // found the first proabable answer as mid,
            ans = mid;
            // since we have to find the minimized largest sum of the split
            // hence we discard right half of search space
            high = mid - 1;
        }else{
            // otherwise discard left half of search space
            low = mid + 1;
        }
    }
    return ans;
};

let arr = [7,2,5,10,8], k = 2;
// let arr = [1,2,3,4,5], k = 2;

let ans = splitArray(arr, k);
console.log(ans);
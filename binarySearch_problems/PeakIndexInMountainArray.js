
// Problem link - https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

// Approach - 1 (Brute Force)
// TC - O(n)
let peakIndexInMountainArray1 = function(arr) {
    let i = 0;
    while(i < arr.length - 1 && arr[i] < arr[i+1]){
        i++;
    }
    return i;
};

// Approach - 2 (using Binary search)
// TC - O(logn)
let peakIndexInMountainArray = function(arr) {
    let low = 0, high = arr.length - 1;
    while(low < high){
        let mid = low + Math.floor((high - low)/2);
        if(arr[mid] < arr[mid+1]){
            // dicard left half of array
            low = mid + 1;
        }else{
            // got first proabable peak element index
            high = mid;
        }
    }
    return high;
};

let arr = [0,10,5,2];
let ans = peakIndexInMountainArray(arr);
console.log(ans);
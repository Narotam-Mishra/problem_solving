
// 2426. Number of Pairs Satisfying Inequality
// Problem Link - https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/

let count;

function countInequalities(arr, s, mid, e, diff){
    let i = s, j = mid+1;

    // count pairs as per given equation
    while(i <= mid && j <= e){
        if(arr[i] <= arr[j]+diff){
            count += (e - j + 1);
            i++;
        }else{
            j++;
        }
    }
    return;
}

function mergeSortedArray(arr, l, mid, r){
    let i = l, j = mid+1, k=0;
    let temp = [];

    while(i<=mid && j<=r){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }

    // copy back remaining elements from left sub array
    while(i <= mid){
        temp[k++] = arr[i++];
    }

    // copy back remaining elements from left sub array
    while(j <= r){
        temp[k++] = arr[j++];
    }

    // copy back elements from temp arr to original arr
    for(let p=0; p<temp.length; p++){
        arr[l+p] = temp[p];
    }
    return;
}

function mergeSort(arr, s, e, diff){
    // base case:
    if(s === e) return;

    // using recursive merge sort technique
    // calculate mid
    let mid = Math.floor((s + e)/2);
    // recursively call mergesort() on left half of array
    mergeSort(arr, s, mid, diff);
    // recursively call mergesort() on right half of array
    mergeSort(arr, mid+1, e, diff);
    // count pairs
    countInequalities(arr, s, mid, e, diff);
    // merge sorted array
    mergeSortedArray(arr, s, mid, e);
}

let numberOfPairs = function(nums1, nums2, diff) {
    count = 0;
    let size = nums1.length; 
    let diffArr = Array(size);
    
    // find differnce in diffArr array
    for(let i=0; i<size; i++){
        diffArr[i] = nums1[i] - nums2[i];
    }
    // use merge sort logic on diffArr
    mergeSort(diffArr, 0, size-1, diff);
    return count;
};

// let arr1 = [3,2,5]
// let arr2 = [2,2,1]
// let diff = 1;

let arr1 = [-4,-4,4,-1,-2,5]
let arr2 = [-2,2,-1,4,4,3]
let diff = 1;
let ans = numberOfPairs(arr1, arr2, diff);
console.log(ans);
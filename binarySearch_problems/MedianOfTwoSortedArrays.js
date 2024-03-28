
// Problem link - https://leetcode.com/problems/median-of-two-sorted-arrays/

// Approach - Brute Force Method

function mergeTwoSortedArrays(arr1, arr2, m, n){
    let i = 0, j = 0, k = 0;

    let res = Array(m+n).fill(0);
    while(i < m && j < n){
        if(arr1[i] < arr2[j]){
            res[k] = arr1[i];
            k++;
            i++;
        }else{
            res[k] = arr2[j];
            k++;
            j++;
        }
    }

    // if any element left in arr1
    while(i < m){
        res[k] = arr1[i];
        k++;
        i++;
    }

    // if any element left in arr2
    while(j < n){
        res[k] = arr2[j];
        k++;
        j++;
    }

    // console.log("Merged Array:",...res);
    return res;
}

let findMedianSortedArrays = function(nums1, nums2) {
    let m = nums1.length, n = nums2.length;

    let mergedArr = mergeTwoSortedArrays(nums1, nums2, m, n);
    // console.log(mergedArr);

    let size = mergedArr.length;
    let mid = Math.floor(size/2);

    // if array length is even
    if(size % 2 === 0){
        let f = mergedArr[mid];
        let s = mergedArr[mid - 1];
        return (f+s)/2;
    }else{
        return mergedArr[mid];
    }
};

// Approach - 2 (Merge Sort technique with space optimized)
let findMedianSortedArrays1 = function(nums1, nums2) {
    let m = nums1.length, n = nums2.length;
    let i = j = 0;
    let len = m + n;
    let mid = Math.floor(len/2);
    let preMid = mid - 1;
    let cnt = 0;
    let indNum1 = -1, indNum2 = -1;

    while(i < m && j < n){
        if(nums1[i] < nums2[j]){
            if(cnt === preMid) indNum1 = nums1[i];
            if(cnt === mid) indNum2 = nums1[i];
            cnt++;
            i++;
        }else{
            if(cnt === preMid) indNum1 = nums2[j];
            if(cnt === mid) indNum2 = nums2[j];
            cnt++;
            j++;
        }
    }

    // if any element left in nums1
    while(i < m){
        if(cnt === preMid) indNum1 = nums1[i];
        if(cnt === mid) indNum2 = nums1[i];
        cnt++;
        i++;
    }

    // if any element left in nums2
    while(j < n){
        if(cnt === preMid) indNum1 = nums2[j];
        if(cnt === mid) indNum2 = nums2[j];
        cnt++;
        j++;
    }

    // if size is odd
    if(len%2 == 1){
        return indNum2
    }

    return (indNum1 + indNum2)/2.0;
};

// let nums1 = [1,3];
// let nums2 = [2];

let nums1 = [1,2];
let nums2 = [3,4];
// let ans = findMedianSortedArrays(nums1, nums2);
let ans = findMedianSortedArrays1(nums1, nums2);
console.log(ans);
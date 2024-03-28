
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

// let nums1 = [1,3];
// let nums2 = [2];

let nums1 = [1,2];
let nums2 = [3,4];
let ans = findMedianSortedArrays(nums1, nums2);
console.log(ans);

// Problem link - https://leetcode.com/problems/merge-sorted-array/description/

// Approach - 1 (Efficient Approach)
// Time Complexity - O(m+n)

let merge = function(nums1, m, nums2, n) {
    let i=0, j=0, k=0;
    let res = Array(m+n);

    while(i<m && j<n){
        if(nums1[i] <= nums2[j]){
            res[k] = nums1[i];
            k++;
            i++;
        }else{
            res[k] = nums2[j];
            k++;
            j++;
        }
    }

    // if i === m, nums1 is exhausted
    while(j < n){
        res[k] = nums2[j];
        k++;
        j++;
    }

    // if j === n, nums2 is exhausted
    while(i < m){
        res[k] = nums1[i];
        k++;
        i++;
    }

    k = 0;
    while(k < m+n){
        nums1[k] = res[k]
        k++;
    }
};


// Approach - 2 (without using extra array)
// TC - O(m+n)
let merge1 = function(nums1, m, nums2, n) {
    let i = m-1, j = n-1, k = m+n-1;

    while(i>=0 && j>=0){
        if(nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            k--;
            i--;
        }else{
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }

    // nums2 is exhausted
    while(i>=0){
        nums1[k] = nums1[i];
        k--;
        i--;
    }

    // nums1 is exhausted
    while(j>=0){
        nums1[k] = nums2[j];
        k--;
        j--;
    }
};
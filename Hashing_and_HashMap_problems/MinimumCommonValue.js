
// Problem link : https://leetcode.com/problems/minimum-common-value/description/?envType=problem-list-v2&envId=hash-table

let getCommon1 = function(nums1, nums2) {
    // step 1 - intialize two pointers for both arrays `nums1` & `nums2`
    let i = 0, j = 0;

    // step 2 - iterate both arrays using two pointers
    while(i < nums1.length && j < nums2.length){
        // if both numbers are equal
        if(nums1[i] === nums2[j]){
            // then we found the smallest common integer
            return nums1[i];
        }else if(nums1[i] < nums2[j]){
            // move pointer in nums1 forward
            i++;
        }else{
            // move pointer in nums2 forward
            j++;
        }
    }

    // step 3 - otherwise return -1
    return -1;
};

let getCommon = function(nums1, nums2) {
    // step 1 - create set and store `nums1` values
    const numSet = new Set(nums1);

    // step 2 - iterate nums2 
    for(let num of nums2){
        // and check nums2's element is already present in numsSet
        if(numSet.has(num)){
            // if already present, return the first common number found
            return num;
        }
    }

    // step 3 - otherwise return -1
    return -1;
};

const nums1 = [1,2,3], nums2 = [2,4];

// const nums1 = [1,2,3,6], nums2 = [2,3,4,5];
console.log(getCommon(nums1, nums2));

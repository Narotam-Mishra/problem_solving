
// Problem link - https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/

let mergeArrays = function(nums1, nums2) {
    // store final result in `res`
    const res = [];

    // step 1 - two pointers to track position in `nums1` and `nums2`
    let i = 0, j = 0;

    // step 2 - iterate on both input arrays and perform the given operation
    while(i < nums1.length && j < nums2.length){
        // extract id and value from both arrays
        const id1 = nums1[i][0];
        const val1 = nums1[i][1];

        const id2 = nums2[j][0];
        const val2 = nums2[j][1];

        // step 3 - id1 from nums1 is smaller, so it doesn't exist in nums2
        if(id1 < id2){
            // so add it to the result `res`
            res.push([id1, val1]);
            i++;
        }

        // step 4 - id2 from nums2 is smaller, so it doesn't exist in nums2
        else if(id1 > id2){
            // so add it to the result `res`
            res.push([id2, val2]);
            j++;
        }

        // step 5 - both ids are equal so sum their respective values and add it to `res`
        else{
            res.push([id1, val1+val2]);
            i++;
            j++;
        }
    }

    // step 6 - handle remaining values
    while(i < nums1.length){
        res.push([nums1[i][0], nums1[i][1]]);
        i++;
    }

    while(j < nums2.length){
        res.push([nums2[j][0], nums2[j][1]]);
        j++;
    }

    // step 7 - return final result array `res`
    return res;
};

// const nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]];

const nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]];
console.log(mergeArrays(nums1, nums2));
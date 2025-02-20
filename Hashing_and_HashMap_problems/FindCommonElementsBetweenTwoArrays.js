
// Problem link - https://leetcode.com/problems/find-common-elements-between-two-arrays/description/?envType=problem-list-v2&envId=hash-table

let findIntersectionValues1 = function(nums1, nums2) {
    // step 1 - create sets to store unique elements of both arrays
    const set1 = new Set(nums1);
    const set2 = new Set(nums2);

    // step 2 - initialize counters for the answers
    let ans1 = 0 , ans2 = 0;

    // step 3 - count how many elements in nums1 exist in nums2
    for(let num of nums1){
        if(set2.has(num)){
            ans1++;
        }
    }

    // step 4 - count how many elements in nums2 exist in nums1
    for(let num of nums2){
        if(set1.has(num)){
            ans2++;
        }
    }

    // step 5 - return the results as an array
    return [ans1, ans2];
};

let findIntersectionValues = function(nums1, nums2) {
    // step 1 - initialize counters for the answers
    let ans1 = 0, ans2 = 0;

    // step 2 - count how many elements in nums1 exist in nums2
    for(let num of nums1){
        if(nums2.includes(num)){
            ans1++;
        }
    }

    // step 3 - count how many elements in nums2 exist in nums1
    for(let num of nums2){
        if(nums1.includes(num)){
            ans2++;
        }
    }

    // step 4 - return the results as an array
    return [ans1, ans2];
};

const nums1 = [2,3,2], nums2 = [1,2];

// const nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6];

// const nums1 = [3,4,2,3], nums2 = [1,5];
console.log(findIntersectionValues(nums1, nums2));

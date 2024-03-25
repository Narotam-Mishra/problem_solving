
// Problem link - https://leetcode.com/problems/intersection-of-two-arrays/description/

// Approach1 - Two Pointers 
let intersection = function(nums1, nums2) {

    // sort both arrays
    nums1.sort((a,b) => a-b);
    nums2.sort((a,b) => a-b);

    // take two poinyers to iterate on arrays and find common elements
    let i = j = 0;

    let res = [];
    while(i < nums1.length && j < nums2.length){
        if(nums1[i] < nums2[j]){
            i++;
        }else if(nums1[i] > nums2[j]){
            j++;
        }else{
            // found first common element, also we have to make sure we are not duplicating the same element 
            // as we need to store unique element in result array res[]
            if(res.length === 0 || res[res.length - 1] !== nums1[i]){
                res.push(nums1[i]);
            }
            i++;
            j++;
        }
    }

    return res;
};


// Approach - 2 (using set)

let intersection1 = function(nums1, nums2) {
    // Create a Set to store unique elements
    let numSet = new Set(nums1);
    let intersectionSet = new Set();

    // Iterate on nums2 array and 
    for(let num of nums2){
        // check whether it is present in numSet or not
        if(numSet.has(num)){
            intersectionSet.add(num);
        }
    }

    // return answer in an array
    return Array.from(intersectionSet);
};

// let arr1 = [1,2,2,1];
// let arr2 = [2,2];

let arr1 = [4,9,5];
let arr2 = [9,4,9,8,4];

let ans = intersection1(arr1, arr2);
console.log(...ans);
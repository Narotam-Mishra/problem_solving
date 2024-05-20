
// Problem link - https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

// Approach 1 - Two Pointers 
let intersect = function(nums1, nums2) {

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
            // found first common element, 
            res.push(nums1[i]);
            i++;
            j++;
        }
    }
    return res;
};

// Approach 2 - (using object as HashMap)
let intersect1 = function(nums1, nums2) {
    let map = {}; // object as map to store frquencies of each element
    let res = []; // to store intersection result in res[] array

    // count frequecy of each element of nums1 array
    for(let num of nums1){
        map[num] = (map[num] || 0) + 1;
    }

    // Check for intersecting elements in nums2 and decrement counts in map
    for(let num of nums2){
        if(map[num] > 0){
            res.push(num);
            map[num]--;
        }
    }

    return res;
};

let arr1 = [1,2,2,1];
let arr2 = [2,2];

// let arr1 = [4,9,5];
// let arr2 = [9,4,9,8,4];

let ans = intersect1(arr1, arr2);
console.log(...ans);
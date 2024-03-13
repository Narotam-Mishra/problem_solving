
// Very Very Important Question

// Problem link - https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/

let countSmaller = function(nums) {
    // Initialize an array to store the counts of smaller elements to the right
    let res = Array(nums.length).fill(0);

    // create array of objects with input array element sand their indices
    let indexNums = nums.map((num, index) => ({num, index}));

    // let us use mergeSort algorithm
    function mergeSort(arr){
        // Base case: array of 1 element is always sorted, hence return
        if(arr.length === 1) return arr;

        // calculate mid and recurively sort left and right half of array
        let mid = Math.floor(arr.length / 2);

        // recurively sort left and right half of array
        let leftArr = mergeSort(arr.slice(0, mid));
        let rightArr = mergeSort(arr.slice(mid));

        // Merge the sorted left and right halves while counting smaller elements from the right side
        return mergeArrays(leftArr, rightArr);
    }

    // let us define merge function to merge two sorted arrays
    function mergeArrays(left, right){
        let i=0, j=0, sortedArr = [];

        while(i < left.length || j < right.length){
            // If the element from the left array is smaller or equal, add it to the sorted array
            if(j === right.length || (i < left.length && left[i].num <= right[j].num)){
                sortedArr.push(left[i]);

                // Count smaller elements from the right side by adding the current count (j) to result
                res[left[i].index] += j;
                i++;
            }else{
                sortedArr.push(right[j]);
                j++;
            }
        }

        // return sorted array
        return sortedArr
    }

    // Call mergeSort on the indexedNums array (with indices) to get the sorted array
    mergeSort(indexNums);

    return res;
};

let nums = [5,2,6,1];
// let nums = [2,0,1];

let ans = countSmaller(nums);
console.log("Count od Smaller Numbers in right side:",...ans);
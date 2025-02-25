
// Problem link - https://leetcode.com/problems/kth-missing-positive-number/description/?envType=problem-list-v2&envId=binary-search

// Approach - 1 (uaing Linear search)

let findKthPositive1 = function(arr, k) {
    // count of missing numbers found
    let missingCounts = 0;

    // start from the first natural number
    let current = 1;

    // pointer for array
    let index = 0;

    while(missingCounts < k){
        // if the current number is in the array, move to the next element
        if(index < arr.length  && current == arr[index]){
            index++;
        } else {
            // otherwise, it's a missing number
            missingCounts++;

            // found missing number
            if(missingCounts === k) return current;

        }
        // move to next natural number in sequence
        current++;
    }
    return -1;
};

// Approach - 2 (Binary Search)

let findKthPositive = function(arr, k) {
    // define the search space
    let s = 0, e = arr.length - 1;

    // step 1 - use binary search logic
    while(s <= e){
        // calculate mid
        let mid = Math.floor((s + e) / 2);

        // calculate the number of missing number counts
        let missingCounts = arr[mid] - (mid + 1);

        // if the missing numbers are less than k, move to the right
        if(missingCounts < k){
            s = mid + 1;
        }
        // if the missing numbers are greater than or equal to k, move to the left 
        else {
            e = mid - 1;
        }
    }

    // return kth missing number
    return k + e + 1;
};

const arr = [2,3,4,7,11], k = 5;

// const arr = [1, 2, 3, 4], k = 2;
console.log(findKthPositive(arr, k)); 

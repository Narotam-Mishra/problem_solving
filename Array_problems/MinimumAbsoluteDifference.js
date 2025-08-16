
// Problem link - https://leetcode.com/problems/minimum-absolute-difference/description/?envType=problem-list-v2&envId=array

let minimumAbsDifference = function(arr) {
    const n = arr.length;

    // store minimum absolute difference in `minDiff`
    let minDiff = Infinity;

    // step 1 - sort the array
    arr.sort((a,b) => a - b);

    // step 2 - check all pairs for minimum absolute difference
    for(let i=0; i<n-1; i++){
        // always positive since array is sorted
        const currDiff = arr[i+1] - arr[i];
        minDiff = Math.min(currDiff, minDiff);
    }

    // step 3 - iterate through adjacent pairs again to find all with min difference
    const res = [];
    for(let i=0; i<n-1; i++){
        const currDiff = arr[i+1] - arr[i];

        // step 4 - if this pair has the minimum difference, add it to result
        if(currDiff === minDiff){
            res.push([arr[i], arr[i+1]]);
        }
    }

    // step 5 - return resultant array `res`
    return res;
};

// const arr = [4,2,1,3];

const arr = [1,3,6,10,15];

// const arr = [3,8,-10,23,19,-4,-14,27]
console.log(minimumAbsDifference(arr));
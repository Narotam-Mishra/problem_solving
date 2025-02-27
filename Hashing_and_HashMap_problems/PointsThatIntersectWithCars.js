
// Problem link - https://leetcode.com/problems/points-that-intersect-with-cars/description/?envType=problem-list-v2&envId=hash-table

let numberOfPoints = function(nums) {
    // step 1 - create set to store unique covered points
    const coveredPoints = new Set();

    // step 2 - iterate over each car's parking range
    for(let [start, end] of nums){
        // add each integer point from start to end into the set
        for(let i=start; i<=end; i++){
            coveredPoints.add(i);
        }
    }

    // step 3 - return the size of set 
    return coveredPoints.size;
};

// const nums = [[3,6],[1,5],[4,7]];

const nums = [[1,3],[5,8]];
console.log(numberOfPoints(nums));

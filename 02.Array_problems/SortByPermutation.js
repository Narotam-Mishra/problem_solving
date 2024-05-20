
// Worst Sorting Algorithm
// sort array's numbers by generating their permutation

// TC of this algorithm is O(n * n!) 

const generateArrayPermutations  = require('./GenerateArrayPermutations');

// function to check if array is sorted or not
function isSorted(arr){
    for(let i=1; i<arr.length; i++){
        if(arr[i-1] > arr[i]) return false;
    }
    return true;
}


let arr = [3,2,5,1];

// generating all permuations of array's numbers
let perArr = generateArrayPermutations(arr);

for(let i=0; i<perArr.length; i++){
    // checking if any of the permuations are sorted or not
    let isArraySorted = isSorted(perArr[i]);

    // if any of array's permuations are sorted then print that array
    if(isArraySorted){
        console.log(perArr[i]);
    }
}




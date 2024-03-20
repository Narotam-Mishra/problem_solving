
// Problem link - https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

function findLowerBound(arr, x){
    let s = 0, e = arr.length-1;
    let ans = arr.length;

    while(s <= e){
        let mid = s + Math.floor((e - s)/2);
        if(x > arr[mid]){
            // discard left half of array
            s = mid + 1;
        }else{
            // first probable ans found
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}

let successfulPairs = function(spells, potions, success) {
    // Sort potions array in ascending order
    potions.sort((a,b) => a-b);
    let successPairs = [];

    for(let spell of spells){
        // minimum strength required for success
        let minStrength = Math.ceil(success / spell);
        // Count successful pairs
        let countSuccessPairs = potions.length - findLowerBound(potions, minStrength);
        successPairs.push(countSuccessPairs);
    }

    return successPairs;
};

// let spells = [3,1,2];
// let potions = [8,5,8];
// let success = 16;

let spells = [5,1,3];
let potions = [1,2,3,4,5];
let success = 7;

let res = successfulPairs(spells, potions, success);
console.log("Sucessful pair array:",...res);
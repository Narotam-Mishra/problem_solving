
// Problem link - https://leetcode.com/problems/delete-columns-to-make-sorted/description/?envType=daily-question&envId=2025-12-20

let minDeletionSize = function(strs) {
    // get size of array of string
    const n = strs.length;

    // get size of each string
    const k = strs[0].length;

    // step 1 - iterate on each letter of string array
    let count = 0;
    for(let i=0; i<k; i++){
        for(let j=1; j<n; j++){
            // step 2 - check if current letter is less than previous letter of word
            if(strs[j][i] < strs[j-1][i]){
                // increment count and break
                count++;
                break;
            }
        }
    }

    // step 3 - return number of columns that you will delete
    return count;
};

// const strs = ["cba","daf","ghi"];

// const strs = ["a","b"];

const strs = ["zyx","wvu","tsr"];
console.log(minDeletionSize(strs));
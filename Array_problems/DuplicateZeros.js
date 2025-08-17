
// Problem link - https://leetcode.com/problems/duplicate-zeros/description/?envType=problem-list-v2&envId=array

let duplicateZeros = function(arr) {
    const n = arr.length;

    // step 1 - count zeros in `arr` array
    let countZeros = 0;
    for(let num of arr){
        if(num === 0) countZeros++;
    }

    // step 2 - work backwards from the end to avoid overwriting unprocessed elements
    let i = n - 1;
    let writePosition = n + countZeros - 1;

    // step 3 - process element from right to left
    while(i >= 0){
        // step 4 - if write position is within the bound of original array
        if(writePosition < n){
            // place non-zero element
            arr[writePosition] = arr[i];
        }

        // step 5 - if current element is zero, we need to duplicate it
        if(arr[i] === 0){
            // move write position to left for the duplicate
            writePosition--;

            // duplicate zero only if within bound 
            if(writePosition < n){
                arr[writePosition] = 0;
            }
        }

        // step 6 - move both pointers
        i--;
        writePosition--;
    }
};

const arr = [1,0,2,3,0,4,5,0];
console.log("Original Input:",arr);

duplicateZeros(arr);
console.log("Output After Duplicating Zeros:",arr);
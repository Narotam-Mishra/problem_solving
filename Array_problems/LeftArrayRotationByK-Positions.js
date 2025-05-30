

/* let arr = [1,2,3,4,5], k = 2
   Output = [3, 4, 5, 1, 2]
*/

// Approach - 1 Brute Force (Left Rotate)
let leftRotateArrayByKPositions = function(arr, k){
    let n = arr.length;
    
    // Base case:
    if(k > n || k == 0 || k === 1) return;

    let res = [];

    k = k % n;
    for(let i=k; i<n; i++){
        res.push(arr[i]);
    }

    for(let i=0; i<k; i++){
        res.push(arr[i]);
    }

    return res;
}

let rightRotateArrayByKPositions = function(arr, k){
    let n = arr.length;

    // Base case:
    if(k > n || k == 0 || k === 1) return;

    let res = [];
    k = k % n;
    for(let i=n-k; i<n; i++){
        res.push(arr[i]);
    }

    for(let i=0; i<n-k; i++){
        res.push(arr[i]);
    }

    return res;
}

let leftRotateArrayByKPositionsInPlace = function(arr, k){
    let size = arr.length;
    if(k > size || k == 0 || k === 1) return;

    k = k % size;

    function reverseArray(start, end){
        while(start < end){
            let temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    reverseArray(0, k-1);
    reverseArray(k, size-1);
    reverseArray(0, size-1);
}

// const arr = [1, 2, 3, 4, 5], k = 2;
// console.log("Left Roate:", leftRotateArrayByKPositions(arr, k));
// console.log("Right Roate:", rightRotateArrayByKPositions(arr, k));

const arr = [1, 2, 3, 4, 5], k = 2;
leftRotateArrayByKPositionsInPlace(arr, k);
console.log("After Left Roate In Place:", arr);

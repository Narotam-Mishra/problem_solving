
// Problem link - https://www.spoj.com/problems/INVCNT/

function mergeArray(arr, s, e){
    // calculate mid
    let mid = Math.floor((s+e)/2);
    let i=s, j=mid+1, k=s, ic=0;
    let res = Array(1000);

    // Merge the arrays
    while(i<=mid && j<=e){
        if(arr[i] < arr[j]){
            res[k] = arr[i];
            i++;
            k++;
        }else{
            res[k] = arr[j];
            j++;
            k++;
            // count for cross inversions
            ic += mid-i+1;
        }
    }

    // if right part of array is exhausted, then copy ramaining elements from left array to res array
    while(i<=mid){
        res[k] = arr[i];
        i++;
        k++;
    }

    // if left part of array is exhausted, then copy ramaining elements from right array to res array
    while(j<=e){
        res[k] = arr[j];
        j++;
        k++;
        // Increment counter for cross inversions
        ic += mid-i+1;
    }

    // copy back element to original array
    for(let id=s; id<=e; id++){
        arr[id] = res[id];
    }
    // return the count of cross inversions
    return ic;
}

function countInversion(arr, s, e){
    // Base case
    if(s>=e){
        return 0;
    }

    // Recursive case: count inversion in left and right part of array recursively
    let mid = Math.floor((s+e)/2);
    // Recursively count inversions in left half of array
    let lc = countInversion(arr, s, mid);
    // Recursively count inversions in right half of array
    let rc = countInversion(arr, mid+1, e);
    // merge arrays and count cross inversions
    let ac = mergeArray(arr, s, e);
    // return total count of inversions
    return lc+rc+ac;
}

let arr = [2,3,8,6,1];
let ans = countInversion(arr, 0, arr.length-1);
console.log(ans);
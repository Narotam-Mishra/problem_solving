/*
Find the first peak element in the array {1, 1, 3, 4, 2, 3, 5, 7, 0}
Peak element is the one which is greater than its immediate left neighbor and its immediate right neighbor.
Leftmost and rightmost element cannot be a peak element.

Here Peak element will be either of 4 or 7
*/

// Approach - 1 (using Binary search algorithm)

function findPeakNumber(arr,n){
    let l = 0, r = n-1, mid;

    while(l<r){
        mid = Math.floor((l+r)/2);
        if(arr[mid] > arr[mid+1]) r = mid;
        else l = mid+1
    }
    return arr[l];
}

let arr = [1,1,3,4,2,3,5,7,0];
console.log(findPeakNumber(arr, arr.length));


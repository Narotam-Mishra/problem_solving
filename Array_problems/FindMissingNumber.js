
/*

Given an array arr[] of size N-1 with integers in the range of [1, N], the task is to find the 
missing number from the first N integers. There are no duplicates in the list.

n = 7
arr[] = {1,2,4,6,3,7,8}

Expected Output: 5

Sum of first N natural numbers = (N * N+1)/2

*/

function findMissing(arr,n){
    let nSum = Math.floor(((n+1) * (n+2))/2);
    let arrSum = 0;
    for(let i=0; i<n; i++){
        arrSum += arr[i];
    }
    let missNum = nSum - arrSum;
    return missNum;
}

let arr = [1,2,4,6,3,7,8];
let n = 7
console.log(findMissing(arr, n));
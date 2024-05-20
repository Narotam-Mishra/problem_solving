
/*

You are given an integer array of size n and you are given element 'x'. Return the index of the first value greater than 'x'.

*/

function findUpperBound(arr, x){
    let s = 0, e = arr.length-1;
    let ans = -1;

    while(s <= e){
        let mid = s + Math.floor((e - s)/2);
        if(arr[mid] <= x){
            // discard the left half
            s = mid + 1;
        }else{
            // in right half we will get the first probable ans
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}

let arr = [2,2,3,3,3,4,6,6,8];
let res = findUpperBound(arr,4);
console.log(res);
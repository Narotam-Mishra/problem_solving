
/*

You are given an integer array of size n and you are given element 'x'. Return the index of the first value greater than or equal to 'x'.

*/

function findLowerBound(arr, x){
    let s = 0, e = arr.length-1;
    let ans = -1;

    while(s <= e){
       let mid = s + Math.floor((e - s)/2);
       if(x > arr[mid]){
            s = mid + 1;
        }else{
            // first probable ans found
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}

let arr = [1,2,2,3,3,5];
let ans = findLowerBound(arr,3);
console.log(ans);
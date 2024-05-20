
// Problem link - https://www.interviewbit.com/problems/smaller-or-equal-elements/

function countSmallerAndEqual(arr, x){
    let s = 0, e = arr.length - 1;
    let ans = arr.length;

    while(s <= e){
        let mid = s + Math.floor((e - s)/2);
        if(arr[mid] <= x){
            // discard left
            s = mid + 1;
        }else{
            ans = mid;
            e = mid - 1;
        }
    }
    return ans;
}

// let arr = [1,3,4,4,6];
let arr = [1,2,5,5];

let ans = countSmallerAndEqual(arr, 3);
console.log(ans);
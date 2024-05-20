
// Problem link - https://hack.codingblocks.com/app/contests/5320/199/problem

function binarySearch(arr, key){
    let s = 0, e = arr.length-1;

    while(s <= e){
        let mid = s + Math.floor((e - s)/2);

        if(arr[mid] === key){
            return mid;
        }else if(key > arr[mid]){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return -1
}

let arr = [2,3,4,5,7,8,9];
console.log(binarySearch(arr, 9));

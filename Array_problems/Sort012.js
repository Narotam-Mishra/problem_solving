
// sort array of 0, 1 & 2

function sortZeroOneTwo(arr){
    let s = 0;
    let mid = 0;
    let e = arr.length - 1;

    while(mid <= e){
        if(arr[mid] === 0){
            [arr[s], arr[mid]] = [arr[mid], arr[s]];
            s++;
            mid++;
        }else if(arr[mid] === 1){
            mid++;
        }else{
            [arr[e], arr[mid]] = [arr[mid], arr[e]];
            e--;
        }
    }
    return arr;
}

const nums = [1,2,0,2,1,0,2];
console.log("Before Sorting:", nums);

sortZeroOneTwo(nums);
console.log("After Sorting:", nums);
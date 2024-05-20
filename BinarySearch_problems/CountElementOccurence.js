
// Problem link - https://www.interviewbit.com/problems/count-element-occurence/

function findLeftIndex(arr, target){
    let s = 0, e = arr.length - 1;
    let leftIndex = -1;

    while(s <= e){
        let mid = s + Math.floor((e - s)/2);
        if (arr[mid] >= target){
            if(arr[mid] === target){
                leftIndex = mid;
            }
            e = mid - 1
        }else{
            s = mid + 1;
        }
    }
    return leftIndex;
}

function findRightIndex(arr, target){
    let s = 0, e = arr.length - 1;
    let rightIndex = -1;

    while(s <= e){
        let mid = s + Math.floor((e - s)/2);
        if (arr[mid] <= target){
            if(arr[mid] === target){
                rightIndex = mid;
            }
            s = mid + 1
        }else{
            e = mid - 1;
        }
    }
    return rightIndex;
}
function countElementOccurence(arr, x){
    let leftIndex = findLeftIndex(arr,x);
    let rightIndex = findRightIndex(arr,x);

    if(leftIndex !== -1 && rightIndex !== -1){
        return rightIndex - leftIndex + 1;
    }
    return -1;
}

let arr = [5, 7, 7, 8, 8, 10];
let target = 8;
let occurrences = countElementOccurence(arr, target);
console.log(occurrences);

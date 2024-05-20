
// Second Worst Sorting Algorithm - Bogo Sort

function isSorted(arr){
    for(let i=1; i<arr.length; i++){
        if(arr[i-1] > arr[i]) return false;
    }
    return true;
}

function bogoSort(arr){
    // check till the array is sorted
    while(!isSorted(arr)){
        // shuffle the array
        for(let i=arr.length-1; i>0; i--){
            let j = Math.floor(Math.random() * (i+1));
            [arr[i], arr[j]] = [arr[j], arr[i]];
        }
    }
    return arr;
}

let arr = [3,2,5,1,6,7];
console.log("Unsorted array: ",arr);

let res = bogoSort(arr);
console.log("Sorted array:", res);

// sort array's numbers using Bubble sort 

function bubbleSort(arr){
    for(let i=0; i<arr.length; i++){
        isSwapped = false;
        for(let j=0; j<arr.length-i-1; j++){
            if(arr[j] > arr[j+1]){
                let temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSwapped = true;
            }
        }
        // if swapping occured then that means array is already sorted return as it is
        if(isSwapped === false) return ;
    }
}


let arr = [5,2,7,1,4,3];
// let arr = [3,4,5,7,8,9];

console.log("Unsorted array: ",arr);
let t1 = performance.now();

bubbleSort(arr);

let t2 = performance.now();
console.log("Sorted array: ",arr);


console.log("Time spent: ", Math.floor(t2 - t1));


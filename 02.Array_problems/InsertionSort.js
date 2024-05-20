
// sort the array's elements using Insertion sort

function insertionSort(arr){
    for(let i=1; i<arr.length; i++){
        // array with 1 element is always sorted
        let currVal = arr[i];

        let j;
        for(j=i-1; j>=0; j--){
            // check if previous value of array greater than current value 
            if(arr[j] > currVal){
                //then shift previous value to the unsorted region of array
                arr[j+1] = arr[j];
            }else{
                // arr[j] <= currVal
                break;
            }
        }
        // insert current value at its correct place
        arr[j+1] = currVal;
    }
};


// let arr = [2,3,4,5,6,7];
let arr = [7,2,6,1,5,3,4];

console.log("Unsorted Array: "+arr);
let t1 = performance.now();

insertionSort(arr);

let t2 = performance.now();
console.log("Sorted Array: "+arr);

console.log("Time taken: "+Math.floor(t2-t1));
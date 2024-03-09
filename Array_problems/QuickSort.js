
/*

# sort the array using Quick sort algorithm

# Steps to sort array using Quick Sort :-
1). Find pivot elemnt in array using partition of array
2). Divide the array about pivot
3). Recursively sort the 2 parts of array

*/

// Quick sort's implementation

function findPivotIndexUsingPartition(arr, s, e){
    // assume array's last element is pivot element
    let i = s-1, pivot = arr[e];

    for(let j=s; j<e; j++){
        if(arr[j] < pivot){
            i++;
            // perform swap to bring smaller element to left of pivot element
            let temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // perform swap to bring pivot element to correct position in array
    let tem = arr[i+1]
    arr[i+1] = arr[e];
    arr[e] = tem;
    // 
    return i+1;
}

function quickSort(arr, start, end){
    // Base case
    if(start >= end){
        return;
    }

    //Step - 1: find pivot element's index using findPivotIndexUsingPartition() method
    let pivotIndex = findPivotIndexUsingPartition(arr, start, end);
    // Step - 2 & 3: after finding pivot element's index, recursively sort two partitions of arrays
    quickSort(arr, start, pivotIndex-1);
    quickSort(arr, pivotIndex+1, end);
}

let arr = [7,1,6,2,5,3,4];
console.log("Unsorted Array: ",...arr);

quickSort(arr, 0, arr.length-1);

console.log("Sorted Array: ",...arr);


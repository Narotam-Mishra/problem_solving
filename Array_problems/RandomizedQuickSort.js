
// sort array's elements using Randomized Quick sort

function shuffleArray(arr, e){
    for(let i=e; i>0; i--){
        // j will be within the bounds of the array from 0 to i.
        let j = Math.floor(Math.random() * (i+1));

        // swap array elements to shuffle
        [arr[i], arr[j]] = [arr[j], arr[i]];
    }
}

function getPivotIndexUsingPartition(arr, s, e){
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

function randomizedQuickSort(arr, s, e){
    // Base case: if start and end index are equal then return
    if(s >= e){
        return;
    }else{
        // recursively sort array by finding pivot element
        // Step1 : find pivot element's index using getPivotIndexUsingPartition() method
        let pivotIndex = getPivotIndexUsingPartition(arr, s, e);

        // Step - 2 & 3: after finding pivot element's index, recursively sort two partitions of arrays
        randomizedQuickSort(arr, s, pivotIndex-1);
        randomizedQuickSort(arr, pivotIndex+1, e);
    }
}

let arr = [7,1,6,2,5,3,4];
console.log("Original Input Array:",...arr);

shuffleArray(arr, arr.length-1);
console.log("Unsorted Shuffled Array:",...arr);

randomizedQuickSort(arr, 0, arr.length-1);
console.log("Sorted Array:",...arr);

// Implement bubble sort using recursion without any single loop

function bubbleSortRec(arr, n){
    // Base case: if only one element remains, array is sorted
    if(n === 1) return arr;

    // Move the largest element to the end of array using bubbleSortHelper()
    bubbleSortHelper(arr, n-1, 0);

    // recursively call bubbleSortRec() on reduced array (excluding the last element)
    bubbleSortRec(arr, n-1);
}

function bubbleSortHelper(arr, n, i){
    // Base case: if we reached the end of array then return
    if(i === n) return;

    // if the current element is greater than the next element, then swap them
    if(arr[i] > arr[i+1]){
        [arr[i], arr[i+1]] = [arr[i+1], arr[i]];
    }

    // recursively call bubbleSortHelper() on the next array's elements
    bubbleSortHelper(arr, n, i+1);
}

const array = [64, 34, 25, 12, 22, 11, 90];
bubbleSortRec(array, array.length);
console.log("Sorted Arrays Using Bubble sort:", array);
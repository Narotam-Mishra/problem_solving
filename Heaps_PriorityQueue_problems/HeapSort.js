
// Implement Heap sort using Heaps

// utility function to build heap
function heapify(arr, n, i){
    // intilize largest as root
    let largest = i;

    // find left and right child index
    let lcIdx = 2*i + 1;
    let rcIdx = 2*i + 2;

    // if left child is larger than root
    if(lcIdx < n && arr[lcIdx] > arr[largest]){
        largest = lcIdx;
    }

    // if right child is larger than root
    if(rcIdx < n && arr[rcIdx] > arr[largest]){
        largest = rcIdx;
    }

    // if largest is not root
    if(largest !== i){
        // swapping
        [arr[i], arr[largest]] = [arr[largest], arr[i]];

        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// utility function to perform heap sort
function heapSort(arr){
    let size = arr.length;

    // build heap from first none-leaf node
    let first_none_leaf_idx = Math.floor(size / 2) - 1;
    for(let i = first_none_leaf_idx; i>=0; i--){
        heapify(arr, size, i);
    }

    // one by one extract an element from heap
    for(let i = size - 1; i > 0; i--){
        // since we have build max-heap
        // so move current root to end
        [arr[0], arr[i]] = [arr[i], arr[0]];

        // call max-heap heapify on reduce part of heap
        heapify(arr, i, 0);
    }
}

let arr = [12, 7, 11, 5, 17, 6, 13];
heapSort(arr);
console.log("Sorted array after heap sort:", arr);
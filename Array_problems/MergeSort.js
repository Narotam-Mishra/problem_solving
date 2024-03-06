
// sort array's numbers using merge sort algorithm

function mergeTask(left, right){
    let m = left.length, n = right.length;
    let i = 0, j = 0, k = 0;
    let res = Array(m+n);

    // compare array's numbers from both left and right arrays
    while(i < m && j < n){
        if(left[i] < right[j]){
            res[k] = left[i];
            i++;
            k++;
        }else{
            res[k] = right[j];
            j++;
            k++;
        }   
    }

    // if right array is exhausted, copy remaining elements from left array
    while(i < m){
        res[k] = left[i];
        i++;
        k++;
    }

     // if left array is exhausted, copy remaining elements from right array
     while(j < n){
        res[k] = right[j];
        j++;
        k++;
    }

    return res;
}

function mergeSortHelper(arr, s, e){
    // Base case: array with single element is always sorted
    if(s === e){
        let res = Array(1);
        res[0] = arr[s];
        return res;
    }

    let mid = Math.floor((s + e)/2);
    // recursive call for left part of array
    let left = mergeSortHelper(arr, s, mid);

    // recursive call for right part of array
    let right = mergeSortHelper(arr, mid+1, e);

    return mergeTask(left, right);
}

let t1 = performance.now();

let arr = [7,2,6,1,5,3,4];
console.log("Unsorted Array:", ...arr);

function mergeSort(){
    let sortArr = mergeSortHelper(arr, 0, arr.length-1);
    console.log("Sorted Array:", ...sortArr);
}
mergeSort();

let t2 = performance.now();
console.log("Time taken:",Math.floor(t2-t1));


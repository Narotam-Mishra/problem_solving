
// Implement Heap sort using Heaps

package Heaps_PriorityQueue_problems;

public class HeapSort {

    // utility method to swap heap's elements
    private static void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // utility method to build heap
    // To heapify a subtree rooted with node i which is an index in arr[]
    private static void heapify(int[] arr, int n, int idx){
        // intilize largest as root
        int largest = idx;

        // find left and right child index
        int lcIdx = 2*idx + 1;
        int rcIdx = 2*idx + 2;

        // if left child is larger than root
        if(lcIdx < n && arr[lcIdx] > arr[largest]){
            largest = lcIdx;
        }

        // if right child is larger than root
        if(rcIdx < n && arr[rcIdx] > arr[largest]){
            largest = rcIdx;
        }

        // if largest is not root
        if(largest != idx){
            swap(arr, idx, largest);

            // recursively heapify the affected sub-tree
            heapify(arr, n, largest);
            return;
        }
    }

    public static void heapSort(int[] arr){
        int size = arr.length;

        // build heap from first none-leaf node
        int first_non_leftNode_idx = size/2 - 1;
        for(int i=first_non_leftNode_idx; i>=0; i--){
            heapify(arr, size, i);
        }

        // one by one extract an element from heap
        for(int i = size-1; i>0; i--){
            // since we have build max-heap, so move current root to end
            // swapping
            swap(arr, 0, i);

            // call max-heap heapify on reduce part of heap
            heapify(arr, i, 0);
        }
    }

    public static void main(String[] args) {
        int[] arr = {12, 7, 11, 5, 17, 6, 13};
        heapSort(arr);
        System.out.println("Sorted array is");
        for (int i = 0; i < arr.length; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
}
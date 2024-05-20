
// sort array's elements using Quick Sort Algorithm

package Array_problems;

import java.util.Arrays;

public class QuickSort {
    public static int findPivotIndexUsingPartition(int[] arr, int s, int e){
        // assume array's last element is pivot element
        int i = s-1, pivot = arr[e];

        for(int j=s; j<e; j++){
            if(arr[j] < pivot){
                i++;
                // perform swap to bring smaller element to left of pivot element
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // bring pivot element to its correct place (by swapping)
        int tem = arr[i+1];
        arr[i+1] = arr[e];
        arr[e] = tem;

        // return pivot element updated index
        return i+1;
    }

    public static void quickSort(int[] arr, int l, int r){
        if(l >= r){
            return;
        }
        //Step - 1: find pivot element's index using findPivotIndexUsingPartition() method
        int pivotIndex = findPivotIndexUsingPartition(arr, l, r);
        // Step - 2 & 3: after finding pivot element's index, recursively sort two partitions of arrays
        quickSort(arr, l, pivotIndex-1);
        quickSort(arr, pivotIndex+1, r);
    }

    public static void main(String[] args) {
        int[] arr = {2,7,6,3,5,1,4};
        System.out.println("Unsorted Array: "+Arrays.toString(arr));
        quickSort(arr, 0, arr.length-1);
        System.out.println("Sorted Array: "+Arrays.toString(arr));
    }
}

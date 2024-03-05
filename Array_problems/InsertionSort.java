
// sort the array's elements using Insertion sort

package Array_problems;

import java.util.Arrays;

/**
 * InsertionSort
 */
public class InsertionSort {
    public static void insertionSort(int[] arr){
        for(int i=1; i<arr.length; i++){
            // array with 1 element is always sorted
            int currVal = arr[i];

            int j = 0;
            for(j=i-1; j>=0; j--){
                // check if the previous value of array is greater than current value
                if(arr[j] > currVal){
                    // then shift previous value to the unsorted region of array
                    arr[j+1] = arr[j];
                }else{
                    // arr[j] <= currVal
                    break;
                }
            }
            // insert current value 'currVal' to its correct position
            arr[j+1] = currVal;
        }
    }

    public static void main(String[] args) {
        int[] arr = {7,2,6,1,5,3,4};
        System.out.println("Unsorted Array: "+Arrays.toString(arr));
        insertionSort(arr);
        System.out.println("Sorted Array: "+Arrays.toString(arr));
    }
}
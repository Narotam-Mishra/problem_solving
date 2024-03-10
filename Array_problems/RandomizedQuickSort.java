package Array_problems;

import java.util.Arrays;
import java.util.Random;

public class RandomizedQuickSort {

    public static void shuffleArray(int[] arr, int s, int e){
        int i, j;
        // generate random indices
        Random rand = new Random();
        for(i=e; i>0; i--){
            // here j will be within the bounds of the array from 0 to i.
            j = rand.nextInt(i+1);
            // swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    public static int getPivotIndexUsingPartition(int[] arr, int s, int e){
        int i = s-1, pivot = arr[e];

        // loop through each element to create partiton into two halves of array
        for(int j=s; j<e; j++){
            if(arr[j] < pivot){
                i++;
                // perform swap to bring smaller element to left of pivot element
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        // bring pivot to its correct position by swapping
        int temp = arr[i+1];
        arr[i+1] = arr[e];
        arr[e] = temp;

        // return pivot index
        return i+1;
    }

    public static void randomizedQuickSort(int[] arr, int s, int e){
        // Base case: if start and end index are equal then return
        if(s >= e){
            return;
        }else{
            // recursively sort array by finding pivot element
            // Step1 : find pivot element's index using getPivotIndexUsingPartition() method
            int pivotIndex = getPivotIndexUsingPartition(arr, s, e);

            // Step - 2 & 3: after finding pivot element's index, recursively sort two partitions of arrays
            randomizedQuickSort(arr, s, pivotIndex-1);
            randomizedQuickSort(arr, pivotIndex+1, e);
        }
    }

    public static void main(String[] args) {
        int[] arr = {2,7,6,3,5,1,4};
        System.out.println("Original Input Array: "+Arrays.toString(arr));
        shuffleArray(arr, 0, arr.length-1);
        System.out.println("Unsorted Shuffle Array: "+Arrays.toString(arr));
        randomizedQuickSort(arr, 0, arr.length-1);
        System.out.println("Sorted Array: "+Arrays.toString(arr));
    }
}

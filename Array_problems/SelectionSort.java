package Array_problems;

import java.util.Arrays;

public class SelectionSort {

    public static int findMinIndex(int[] arr, int i){
        int minIndex = i;
        for(int j=i+1; j<arr.length; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        return minIndex;
    }

    public static void selectionSort(int[] arr){
        for(int i=0; i<arr.length; i++){
            int minIndex = findMinIndex(arr, i);
            if(i != minIndex){
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {4,2,7,1,6,5};
        System.out.println("Unsorted Array: "+Arrays.toString(arr));
        selectionSort(arr);
        System.out.println("Sorted Array: "+Arrays.toString(arr));
    }
}

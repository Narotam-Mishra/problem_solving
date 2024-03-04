
// sort the array by using Bubble sort

package Array_problems;

import java.util.Arrays;

public class BubbleSort {
    
    public static void bubbleSort(int[] arr){
        for(int i=0; i<arr.length; i++){
            boolean isSwapped = false;
            
            for(int j=0; j<arr.length-i-1; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    isSwapped = true;
                }
            }
            if(isSwapped == false) return;
        }
    }

    public static void main(String[] args) {
        int[] arr = {6,2,7,1,4,3,5};
        System.out.println("Unsorted array: "+Arrays.toString(arr));

        bubbleSort(arr);
        System.out.println("Sorted array: "+Arrays.toString(arr));
    }
}

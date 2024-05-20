package Array_problems;

import java.util.*;

/**
 * BogoSort
 */


public class BogoSort {

    public static boolean isSorted(int[] arr){
        for(int i=1; i<arr.length; i++){
            if(arr[i-1] > arr[i]) return false;
        }
        return true;
    }

    public static void shuffleArray(int[] arr){
        Random rand = new Random();
        for(int i=arr.length-1; i>0; i--){
            int j = rand.nextInt(i+1);
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    public static void bogoSort(int[] arr){
        while (!isSorted(arr)) {
            shuffleArray(arr);
        }
    }

    public static void main(String[] args) {
        int[] arr = {4,2,5,1,7,3};
        System.out.println("Unsorted Array:"+ Arrays.toString(arr));
        bogoSort(arr);
        System.out.println("Sorted Array:"+ Arrays.toString(arr));
    }
}
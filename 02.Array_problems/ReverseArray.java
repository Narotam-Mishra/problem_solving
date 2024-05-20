package Array_problems;

public class ReverseArray {

    public static void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static int[] reverseArray(int[] arr){
        int s=0, e=arr.length-1;
        
        while(s<e){
            swap(arr, s, e);
            s++;
            e--;
        }
        return arr;
    }
}

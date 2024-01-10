
// Problem link - https://leetcode.com/problems/rotate-array/description/

package Array_problems;

public class RotateArrayInplace {

    public static void swap(int[] arr, int s, int e){
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
    }

    public static void reverseArray(int arr[], int i, int j){
        while(i<j){
            swap(arr, i, j);
            i++;
            j--;
        }
    }
    
    public static int[] rotateArrayInPlace(int arr[], int k){
        int n = arr.length;
        k = k % n;
        reverseArray(arr, 0, n-k-1);
        reverseArray(arr, n-k, n-1);
        reverseArray(arr, 0, n-1);
        return arr;
    }
}

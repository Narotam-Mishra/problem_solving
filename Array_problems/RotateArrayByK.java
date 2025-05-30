package Array_problems;

import java.util.Arrays;

public class RotateArrayByK {

    public static int[] rotateArrayByK(int []arr, int k){
        int n = arr.length; k = k%n;
        int res[] = new int[n];
        int j = 0;
        
        for(int i = n-k; i<n; i++){
            res[j++] = arr[i];
        }
        for(int i = 0; i<n-k; i++){
            res[j++] = arr[i];
        }
        return res;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        int k = 2;
        System.out.println(Arrays.toString(rotateArrayByK(arr, k)));
    }
}
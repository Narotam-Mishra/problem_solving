package Array_problems;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class RotateArrayMain {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    private static int[] takeInput() throws NumberFormatException, IOException{
        int size = Integer.parseInt(br.readLine().trim());
        int inputArr[] = new int[size];

        if(size == 0) return inputArr;

        String[] strNums = br.readLine().trim().split("\\s");
        for(int i=0; i<size; i++){
            inputArr[i] = Integer.parseInt(strNums[i]);
        }
        return inputArr;
    }

    private static void printArray(int[] arr){
        for(int num : arr){
            System.out.print(num+" ");
        }
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        int arr[] = takeInput();
        int k = Integer.parseInt(br.readLine().trim());
        // int ans1[] = RotateArrayByK.rotateArrayByK(arr, k);
        int ans[] = RotateArrayInplace.rotateArrayInPlace(arr, k);
        printArray(ans);
    }
}

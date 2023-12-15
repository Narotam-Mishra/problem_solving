package Array_problems;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BuildArray {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static int[] takeInput() throws NumberFormatException, IOException {
        int size = Integer.parseInt(br.readLine().trim());
        int[] input = new int[size];
        
        if(size == 0) {
            return input;
        }
        
        String[] strNums = br.readLine().split("\\s");
        
        for(int i=0; i<size; i++) {
            input[i] = Integer.parseInt(strNums[i]);
        }
        
        return input;
    }

    public static void printArray(int[] arr){
        for(int num : arr){
            System.out.print(num+" ");
        }
        System.out.println();
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        int [] arr = takeInput();
        int res[] = SolutionBuildArray.buildArray(arr);
        printArray(res);
    }
}
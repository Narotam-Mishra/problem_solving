package Array_problems;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * FindUnique
 */
public class FindUnique {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static int[] takeInput() throws NumberFormatException, IOException{
        int size = Integer.parseInt(br.readLine().trim());
        int[] inputArr = new int[size];

        if(size == 0){
            return inputArr;
        }

        String[] strNums = br.readLine().split("\\s");
        for(int i=0; i<size; i++){
            inputArr[i] = Integer.parseInt(strNums[i]);
        }

        return inputArr;
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        int arr[] = takeInput();
        // int ans = SolutionFindUnique1.findUniquenumber(arr);
        int ans = SolutionFindUniqueOptimize.findUnique(arr);
        System.out.println(ans);
    }
}
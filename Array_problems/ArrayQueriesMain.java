package Array_problems;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ArrayQueriesMain {
    
    static BufferedReader br = new BufferedReader((new InputStreamReader(System.in)));

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

    public static int[] makeFreqArray(int arr[]){
        int[] freq = new int[100005];

        for(int i=0; i<arr.length; i++){
            freq[arr[i]]++;
        }
        return freq;
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        int arr[] = takeInput();
        int q = Integer.parseInt(br.readLine().trim());

        int frqArr[] = makeFreqArray(arr);
        
        // for q queries
        while(q > 0){
            int num = Integer.parseInt(br.readLine().trim());

            if(frqArr[num] > 0){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }
            q--;
        }
    }
}

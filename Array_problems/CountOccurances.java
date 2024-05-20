package Array_problems;

import java.util.Scanner;

public class CountOccurances {

    public static int countOccurences(int arr[], int target){
        int count = 0;
        for(int i=0; i<arr.length; i++){
            if(arr[i] == target){
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();

        int arr[] = new int[size];
        for(int i=0; i<size; i++){
            arr[i] = sc.nextInt();
        }
        
        int x = sc.nextInt();
        System.out.println(countOccurences(arr, x));
        sc.close();
    }
}

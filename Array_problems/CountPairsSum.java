package Array_problems;

import java.util.Scanner;

public class CountPairsSum {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();

        int arr[] = new int[size];
        for(int i=0; i<size; i++){
            arr[i] = sc.nextInt();
        }

        int x = sc.nextInt();
        System.out.println(countPairSum(arr,x));
        sc.close();
    }

    public static int countPairSum(int arr[], int target)
    {
        int count = 0;
        for(int i=0; i<arr.length; i++){
            for(int j=i+1; j<arr.length; j++){
                if(arr[i] + arr[j] == target){
                    count++;
                }
            }
        }
        return count;
    }
}
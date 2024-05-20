
// Problem link - https://hack.codingblocks.com/app/contests/5320/199/problem

package BinarySearch_problems;

import java.util.Scanner;

public class BinarySearch {
    public static int binarySearch(int[] arr, int target){
        int s = 0, e = arr.length-1;

        while(s <= e){
            int mid = (s+e)/2;

            if(target == arr[mid]){
                return mid;
            }else if(target > arr[mid]){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] arr = new int[size];

        for(int i=0; i<size; i++){
            arr[i] = sc.nextInt();
        }
        int target = sc.nextInt();
        System.out.println(binarySearch(arr, target));
        sc.close();
    }
}

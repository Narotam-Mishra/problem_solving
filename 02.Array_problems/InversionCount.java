
// Problem link - https://hack.codingblocks.com/app/practice/1/374/problem

package Array_problems;

import java.util.Scanner;

/**
 * InversionCount
 */
public class InversionCount {

    public static int mergeArrayInversionCount(int[] arr, int s, int e){
        int mid = (s+e)/2;
        int i=s, j=mid+1, k=s;
        int ic = 0;

        int[] res = new int[10000];

        // merge arrays
        while(i<=mid && j<=e){
            if(arr[i] < arr[j]){
                res[k++] = arr[i++];
            }else{
                res[k++] = arr[j++];
                // count inversions
                ic += mid-i+1;
            }
        }
        // if right half of array is exhausted
        while(i<=mid){
            res[k++] = arr[i++];
        }

        // if left half of array is exhausted
        while(j<=e){
            res[k++] = arr[j++];
            // count inversions
            ic += mid-i+1;
        }

        // copy back element to original array
        for(int id=s; id<=e; id++){
            arr[id] = res[id];
        }

        // return cross inversion count
        return ic;
    }

    public static int countInversion(int[] arr, int lo, int hi){
        // Base case
        if(lo>=hi){
            return 0;
        }

        // Recursively count inversion in left and right half of array
        int mid = (int)(lo+hi)/2;
        int lc = countInversion(arr, lo, mid);
        int rc = countInversion(arr, mid+1, hi);
        int ac = mergeArrayInversionCount(arr, lo, hi);
        return (lc+rc+ac);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while(tc>0){
            int n = sc.nextInt();
            int arr[] = new int[n];
            for(int i=0; i<n; i++){
                arr[i] = sc.nextInt();
            }
            int ans = countInversion(arr, 0, n-1);
            System.out.println(ans);
            tc--;
        }
        sc.close();
    }
}
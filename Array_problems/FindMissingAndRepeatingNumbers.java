
// Problem link - https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

package Array_problems;

import java.util.Arrays;

public class FindMissingAndRepeatingNumbers {
    public static int[] findMissingAndRepeatingNumber(int arr[], int n) {
        int missingNum = 0, repeatingNum = 0;
        int[] frqArr = new int[n+1];

        for(int i=0; i<n; i++){
            frqArr[arr[i]]++;
        }

        for(int i=1; i<=n ; i++){
            if(frqArr[i] == 0){
                missingNum = i;
            }else if(frqArr[i] == 2){
                repeatingNum = i;
            }
        }

        return new int[]{repeatingNum, missingNum};
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 3};
        int[] ans = findMissingAndRepeatingNumber(arr, arr.length);
        System.out.println(Arrays.toString(ans));
    }
}
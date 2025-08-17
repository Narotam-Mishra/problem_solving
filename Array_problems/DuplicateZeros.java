
// Problem link - https://leetcode.com/problems/duplicate-zeros/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.Arrays;

public class DuplicateZeros {
    public static void duplicateZeros(int[] arr) {
        int n = arr.length;

        // step 1 - count zeros in `arr` array
        int countZeros = 0;
        for (int num : arr) {
            if (num == 0)
                countZeros++;
        }

        // step 2 - work backwards from the end to avoid overwriting unprocessed
        // elements
        int i = n - 1;
        int writePosition = n + countZeros - 1;

        // step 3 - process element from right to left
        while (i >= 0) {
            // step 4 - if write position is within the bound of original array
            if (writePosition < n) {
                // place non-zero element
                arr[writePosition] = arr[i];
            }

            // step 5 - if current element is zero, we need to duplicate it
            if (arr[i] == 0) {
                // move write position to left for the duplicate
                writePosition--;

                // duplicate zero only if within bound
                if (writePosition < n) {
                    arr[writePosition] = 0;
                }
            }

            // step 6 - move both pointers
            i--;
            writePosition--;
        }
    }

    public static void main(String[] args) {
        // int[] arr = {1,0,2,3,0,4,5,0};

        int[] arr = {1,2,3};
        duplicateZeros(arr);
        System.out.println(Arrays.toString(arr));
    }
}

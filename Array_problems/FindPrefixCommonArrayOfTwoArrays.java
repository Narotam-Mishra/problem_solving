
// Problem link - https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2026-05-20

package Array_problems;

import java.util.Arrays;

public class FindPrefixCommonArrayOfTwoArrays {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;

        // keep track of frequency of each element from A & B
        int[] frq = new int[n+1];

        // store final result in `res`
        int[] res = new int[n];

        // keep track of count
        int count = 0;

        // step 1 - iterate over each index i representing prefix [0..i]
        for (int i = 0; i < n; i++) {
            // include A[i] into frequency map
            frq[A[i]]++;

            // step 2 - check if a value's frequency becomes 2 after adding from
            // A,
            if (frq[A[i]] == 2) {
                count += 1;
            }

            // step 3 - include B[i] into frequency map (for B's prefix)
            frq[B[i]]++;

            // step 4 - similarly, if frequency becomes 2 after adding from B,
            if (frq[B[i]] == 2) {
                count += 1;
            }

            // step 5 - store the current number of common elements for prefix
            // [0..i]
            res[i] = count;
        }

        // step 6 - return final result, `res`
        return res;
    }

    public static void main(String[] args) {
        int[] A = {1,3,2,4}, B = {3,1,2,4};
        FindPrefixCommonArrayOfTwoArrays obj = new FindPrefixCommonArrayOfTwoArrays();
        int[] res = obj.findThePrefixCommonArray(A, B);
        System.out.println(Arrays.toString(res));
    }
}

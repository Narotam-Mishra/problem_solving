
// Problem link - https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/?envType=daily-question&envId=2025-09-07

package NumberTheory_Problems;

import java.util.*;

public class FindNUniqueIntegersSumUpToZero {
    public static int[] sumZero(int n) {
        // store result in `res`
        int[] res = new int[n];

        // keep track of array's index
        int index = 0;

        // edge case - if `n` is odd, add 0 
        if(n % 2 == 1){
            res[index++] = 0;
        }

        // step 1 - iterate from 1 to n/2 
        for(int i=1; i<=n/2; i++){
            // step 2 - add number and its negative that can sum up to 0
            res[index++] = i;
            res[index++] = -i;
        }

        // step 3 - return res
        return res;
    }

    public static void main(String[] args) {
        // int n = 5;

        // int n = 3;

        int n = 1;
        int[] res = sumZero(n);
        System.out.println(Arrays.toString(res));
    }
}

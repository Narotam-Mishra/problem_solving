package sliding_window_problems;

import java.util.Arrays;

public class DefuseTheBomb {
    public static int[] decrypt(int[] code, int k) {
        int n = code.length;

        // edge case:
        if(k == 0) return new int[n];

        // `res` array to store decrypted code
        int[] res = new int[n];

        // find the direction of summation based on `k`
        int direction = k > 0 ? 1 : -1;

        // determine number of elements to sum
        int steps = Math.abs(k);

        for(int i=0; i<n; i++){
            // `sum` to store running sum
            int sum = 0;
            for(int j=1; j<=steps; j++){
                // calculate the index of the element to sum using modular arithmetic
                int idx = (i + j * direction + n) % n;
                sum += code[idx];
            }
            // store computed sum in result `res` array
            res[i] = sum;
        }
        // return `res` result array
        return res;
    }

    public static void main(String[] args) {
        // int[] code = {5, 7, 1, 4};
        // int k = 3;

        // int[] code = {1, 2, 3, 4};
        // int k = 0;

        int[] code = {2, 4, 9, 3};
        int k = -2;
        int[] res = decrypt(code, k);
        System.out.println(Arrays.toString(res));
    }
}
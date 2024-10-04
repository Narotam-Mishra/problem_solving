
// Problem link : https://leetcode.com/problems/decode-xored-array/description/?envType=problem-list-v2&envId=bit-manipulation&favoriteSlug=&status=TO_DO&difficulty=EASY

// Key Concept : Inverse of XOR is XOR itself

package BitMasking_Problems;

import java.util.Arrays;

public class DecodeXORedArray {
    public static int[] decode(int[] encoded, int first) {
        int n = encoded.length;
        int[] arr = new int[n+1];

        // initialize the original array with the first element.
        arr[0] = first;

        // reconstruct the rest of the array using the encoded values.
        for(int i=0; i<n; i++){
            arr[i+1] = encoded[i] ^ arr[i];
        }
        // return required array 'arr'
        return arr;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        int first = 1;
        int[] res = decode(arr, first);
        System.out.println(Arrays.toString(res));
    }
}
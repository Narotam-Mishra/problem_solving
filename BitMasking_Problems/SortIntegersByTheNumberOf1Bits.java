
// Problem link : https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

import java.util.*;

public class SortIntegersByTheNumberOf1Bits {
    
    public static int countSetBits(int num){
        int setBits = 0;
        while(num > 0){
            setBits += num & 1;
            num = num >> 1;
        }
        return setBits;
    }

    public static int[] sortByBits1(int[] arr) {
        // convert int[] to Integer[] for object-based sorting
        Integer[] arrInteger = Arrays.stream(arr).boxed().toArray(Integer[]::new);

        // sorting array using custom comparator
        Arrays.sort(arrInteger, (a, b) -> {
            int countA = countSetBits(a);
            int countB = countSetBits(b);

            // sort by value when the number of bits is the same
            if(countA == countB){
                return Integer.compare(a, b);
            }else{
                // otherwise sort by the number of set bits
                return Integer.compare(countA, countB);
            }
        });
        // convert the sorted Integer[] back to int[]
        return Arrays.stream(arrInteger).mapToInt(Integer::intValue).toArray();
    }

    // Method to sort the array based on the number of 1's in binary representation
    public static int[] sortByBits(int[] arr) {
        // Engineer's trick: For each number, we temporarily encode extra information
        // by adding (number of 1's in the binary representation) * 10001 to the number itself.
        // This helps in sorting the array by the number of 1's first, and by the number itself in case of ties.

        for (int i = 0; i < arr.length; i++) {
            // Modify each number by adding the number of 1's in binary form multiplied by 10001
            // Example: If the number is 5 (binary 101, 2 ones), it becomes 5 + 2 * 10001 = 20007.
            arr[i] += Integer.bitCount(arr[i]) * 10001;
        }

        // Sort the modified array. Since each number is increased by (bitCount * 10001),
        // the sort will prioritize the number of 1's in the binary form (because of the large multiplier).
        Arrays.sort(arr);

        // Restore the original numbers by taking modulo 10001, which removes the added part
        // but keeps the array sorted by the number of 1's in binary representation.
        for (int i = 0; i < arr.length; i++) {
            arr[i] = arr[i] % 10001; // Remove the part we added (bitCount * 10001)
        }

        // Return the sorted array
        return arr;
    }

    public static void main(String[] args) {
        // int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

        int nums[] = {1024,512,256,128,64,32,16,8,4,2,1};
        int[] res = sortByBits(nums);
        System.out.println(Arrays.toString(res));
    }
}
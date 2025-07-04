
// Problem link - https://leetcode.com/problems/count-good-triplets/description/?envType=problem-list-v2&envId=array

package Array_problems;

public class CountGoodTriplets {
    public static int countGoodTriplets(int[] arr, int a, int b, int c) {
        // store count of good triplets
        int count = 0;
        int n = arr.length;

        // step 1 - use three nested loops to generate all possible triplets
        // where i < j < k (maintaining the required order)
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {

                    // step 2 - check all three conditions for current triplet
                    // condition-1
                    int diff1 = Math.abs(arr[i] - arr[j]);

                    // condition-2
                    int diff2 = Math.abs(arr[j] - arr[k]);

                    // condition-3
                    int diff3 = Math.abs(arr[i] - arr[k]);

                    // step 3 - if all conditions are satisfied, increment count
                    if (diff1 <= a && diff2 <= b && diff3 <= c) {
                        count++;
                    }
                }
            }
        }

        // step 4 - return count of good triplets
        return count;
    }

    public static void main(String[] args) {
        // int[] arr = {3,0,1,1,9,7};
        // int a = 7, b = 2, c = 3;

        int[] arr = {1,1,2,2,3};
        int a = 0, b = 0, c = 1;
        System.out.println(countGoodTriplets(arr, a, b, c));
    }
}
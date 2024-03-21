
// Problem link - https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/


package Array_problems;

/**
 * MakeArrayZero
 */
public class MakeArrayZero {
    public static int minimumOperations(int[] nums) {
        int[] table = new int[101];

        // add frequency of each non-zero numbers in frequency table
        for(int num : nums){
            table[num] += 1;
        }

        int ans = 0;
        for(int i=1; i<101; i++){
            if(table[i] > 0){
                ans  += 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = {1,5,0,3,5};
        System.out.println(minimumOperations(arr));
    }
}

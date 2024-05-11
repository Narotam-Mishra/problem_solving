
// Problem link - https://leetcode.com/problems/sum-of-subarray-minimums/

package Stack_Problems;

public class SumOfSubArrayMinimums {
    public static int sumSubarrayMins1(int[] arr) {
        int subSum = 0, modNum = 1000000007;
        for(int i=0; i<arr.length; i++){
            int minNum = arr[i];
            for(int j=i; j<arr.length; j++){
                minNum = Math.min(minNum, arr[j]);
                subSum = (subSum + minNum) % modNum;
            }
        }
        return subSum;
    }

    public int sumSubarrayMins(int[] arr) {
        
    }

    public static void main(String[] args) {
        int[] arr = {11,81,94,43,3};
        System.out.println(sumSubarrayMins(arr));
    }
}
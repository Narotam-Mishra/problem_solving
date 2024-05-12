
// Problem link - https://leetcode.com/problems/sum-of-subarray-minimums/

package Stack_Problems;

import java.util.Stack;

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

    public static int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        // using two Arrays to maintain left and right sub-arrays count where arr[i] is minimum
        int[] leftSubArrCnt = new int[n];
        int[] rightSubArrCnt = new int[n];
        // using two Stacks to maintain the elements along with their sub-array counts
        Stack<int[]> st1 = new Stack<>();
        Stack<int[]> st2 = new Stack<>();

        // Find left sub-arrays count where arr[i] is minimum
        for(int i=0; i<n; i++){
            // intial sub-array count will be 1 because there will be atleast one sub-array where arr[i] will be minimum
            int cnt = 1;
            while (!st1.isEmpty() && st1.peek()[0] > arr[i]) {
                cnt += st1.peek()[1];
                st1.pop();
            }
            st1.push(new int[]{arr[i], cnt});
            leftSubArrCnt[i] = cnt;
        }

        // Find right sub-arrays count where arr[i] is minimum
        for(int i=n-1; i>=0; i--){
            // intial sub-array count will be 1 because there will be atleast one sub-array where arr[i] will be minimum
            int cnt = 1;
            while (!st2.isEmpty() && st2.peek()[0] >= arr[i]) {
                cnt += st2.peek()[1];
                st2.pop();
            }
            st2.push(new int[]{arr[i], cnt});
            rightSubArrCnt[i] = cnt;
        }

        // Calculate the required sub-arrays sum using formula --> arr[i] * leftSubArrCnt[i] * rightSubArrCnt[i] 
        long res = 0;
        int modNum = 1000000007;
        for(int i=0; i<n; i++){
            res = (res + (long)arr[i] * leftSubArrCnt[i] * rightSubArrCnt[i]) % modNum;
        }

        // Return answer of 'res'
        return (int)res;
    }

    public static void main(String[] args) {
        int[] arr = {11,81,94,43,3};
        System.out.println(sumSubarrayMins(arr));
    }
}
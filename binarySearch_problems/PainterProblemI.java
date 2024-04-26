
// Problem Link - https://www.interviewbit.com/problems/painters-partition-problem/

package BinarySearch_problems;

import java.util.Arrays;

public class PainterProblemI {
    private static boolean isPossibleToPaintWithMidTimeLimit(int A, int B, int[] C, int mid){
        // start with one pointer
        int totalPainters = 1;
        // Initialize current time to 0 (time taken by the current painter)
        int currentTime = 0;

        // Loop through each board length in the array C
        for(int len : C){
            // if adding time to paint this board exceed the mid time limit
            if(currentTime + (len*B) > mid){
                //then increment total painter as new painter is needed
                totalPainters++;
                // reset the current time
                currentTime = 0;

                // if total painters exceed the no of avaialable painter(A) then return false
                if(totalPainters > A){
                    return false;
                }
            }
            // Add the time taken to paint this board by the current painter
            currentTime += len * B; 
        }

        // If all boards can be painted within the given 'mid' time limit, return true
        return true;
    }
    public static int paint(int A, int B, int[] C) {
        // Minimum time (when one painter paints all boards)
        int maxSum = Arrays.stream(C).max().getAsInt() * B;
        // Maximum time (when each board is painted by a separate painter)
        int totalSum = Arrays.stream(C).sum() * B;
        
        int low = maxSum, high = totalSum;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossibleToPaintWithMidTimeLimit(A,B,C,mid)){
                // find first probable answer as mid
                ans = mid;
                // since we have to find minimum time required to paint all boards
                // hence discard right half of array
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans != -1 ? ans % 10000003 : -1;
    }

    public static void main(String[] args) {
        // int A = 10;
        // int B = 1;
        // int [] C = {1,8,11,3};

        int A = 2;
        int B = 5;
        int[] C = {1,10};
        int ans = paint(A, B, C);
        System.out.println(ans);
    }
}

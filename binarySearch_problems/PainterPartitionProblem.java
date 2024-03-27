package binarySearch_problems;

import java.util.*;

public class PainterPartitionProblem {
    private static boolean isPossibleToPaintWithMidTimeLimit(ArrayList<Integer> C, int k, long mid){
        // start with one pointer
        int totalPainters = 1;
        // Initialize current time to 0 (time taken by the current painter)
        long currentTime = 0;

        // Loop through each board length in the array C
        for(int len : C){
            // if adding time to paint this board exceed the mid time limit
            if(currentTime + len > mid){
                //then increment total painter as new painter is needed
                totalPainters++;
                // reset the current time
                currentTime = 0;

                // if total painters exceed the no of avaialable painter(A) then return false
                if(totalPainters > k){
                    return false;
                }
            }
            // Add the time taken to paint this board by the current painter
            currentTime += len; 
        }

        // If all boards can be painted within the given 'mid' time limit, return true
        return true;
    }

    public static int findLargestMinDistance(ArrayList<Integer> boards, int k) {
        // Minimum time (when one painter paints all boards)
        long maxSum = boards.stream().mapToInt(Integer::intValue).max().orElse(0);
        // Maximum time (when each board is painted by a separate painter)
        long totalSum = boards.stream().mapToInt(Integer::intValue).sum();
        
        long low = maxSum, high = totalSum;
        long ans = -1;

        while(low <= high){
            long mid = low + (high - low)/2;
            if(isPossibleToPaintWithMidTimeLimit(boards, k, mid)){
                // find first probable answer as mid
                ans = mid;
                // since we have to find minimum time required to paint all boards
                // hence discard right half of array
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return (int)ans;
    }

    public static void main(String[] args) {
        // int[] arr = {10, 20, 30, 40};
        // int k = 2;

        ArrayList<Integer> boards = new ArrayList<>(Arrays.asList(10, 20, 30, 40));
        int k = 2;
        int ans = findLargestMinDistance(boards, k);
        System.out.println(ans);
    }
}

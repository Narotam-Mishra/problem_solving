
// Problem link - https://leetcode.com/problems/two-best-non-overlapping-events/?envType=daily-question&envId=2025-12-23

package Array_problems;

import java.util.*;

public class TwoBestNonOverlappingEvents {
    static int n;
    private static int[][] memo;

    private static int binarySearch(int[][] events, int endTime){
        int s = 0;
        int e = n-1;
        int res = n;

        while(s <= e){
            int mid = s + (e - s)/2;
            if(events[mid][0] > endTime){
                res = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return res;
    }

    private static int solveRec(int[][] events, int i, int count){
        // base case
        if(count == 2 || i >= n){
            return 0;
        }

        // if answer is already computed then return its result
        if(memo[i][count] != -1){
            return memo[i][count];
        }

        // recursive case : attend event or skip event
        int nextValidEventIdx = binarySearch(events, events[i][1]);

        // attend event
        int attendEvent = events[i][2] + solveRec(events, nextValidEventIdx, count+1);

        // skip event
        int skipEvent = solveRec(events, i+1, count);

        return memo[i][count] = Math.max(attendEvent, skipEvent);
    }
    
    public static int maxTwoEvents(int[][] events) {
        n = events.length;

        // sort events on the basis of start time
        Arrays.sort(events, Comparator.comparingInt(a -> a[0]));

        // initialize memo
        memo = new int[n+1][3];
        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                memo[i][j] = -1;
            }
        }
        
        // step 1 - solve recursively and return result
        int count = 0;
        return solveRec(events, 0, count);
    }

    public static void main(String[] args) {
        // int[][] events = {{1,3,2},{4,5,2},{2,4,3}};

        // int[][] events = {{1,3,2},{4,5,2},{1,5,5}};

        int[][] events = {{1,5,3},{1,5,1},{6,6,5}};
        System.out.println(maxTwoEvents(events));
    }
}

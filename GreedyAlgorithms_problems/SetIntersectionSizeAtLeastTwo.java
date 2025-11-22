
// Problem link - https://leetcode.com/problems/set-intersection-size-at-least-two/description/

package GreedyAlgorithms_problems;

import java.util.*;

public class SetIntersectionSizeAtLeastTwo {
    public static int intersectionSizeTwo(int[][] intervals) {
        int n = intervals.length;

        // step 1 - sort intervals by ending point ascending
        // if same ending, sort by starting point descending
        Arrays.sort(intervals, (a, b) -> {
            if(a[1] != b[1]){
                return a[1] - b[1];
            }
            return  b[0] - a[0];
        });

        // store final result in `res`
        int res = 0;

        // maintain two chosen intersection points
        int f = -1, s = -1;

        // step 2 - process each intervals
        for(int i=0; i<n; i++){
            int l = intervals[i][0];
            int r = intervals[i][1];

            if(l <= f) continue;

            if(l > s){
                // need two points
                res += 2;
                f = r-1;
                s = r;
            }else{
                // need only one point
                res += 1;
                f = s;
                s = r;
            }
        }

        // step 3 - return final result `res`
        return res;
    }

    public static void main(String[] args) {
        // int[][] intervals = {{1,3},{3,7},{8,9}};

        // int[][] intervals = {{1,3},{1,4},{2,5},{3,5}};

        int[][] intervals = {{1,2},{2,3},{2,4},{4,5}};
        System.out.println(intersectionSizeTwo(intervals));
    }
}

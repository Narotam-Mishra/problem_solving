
// Problem link - https://leetcode.com/problems/count-covered-buildings/description/

package Hashing_and_HashMap_problems;

import java.util.*;

public class CountCoveredBuildings {
    public static int countCoveredBuildings(int n, int[][] buildings) {
        // row(y) -> {minX, maxY}
        Map<Integer, int[]> yMinMaxXMap = new HashMap<>();
        
        // col(x) -> {minY, maxY}
        Map<Integer, int[]> xMinMaxYMap = new HashMap<>();

        // step 1 - build the maps
        for (int[] building : buildings) {
            int x = building[0];
            int y = building[1];

            // initialize row entry if not present
            yMinMaxXMap.putIfAbsent(y, new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE});

            // initialize col entry if not present
            xMinMaxYMap.putIfAbsent(x, new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE});

            // update row minX and maxX
            yMinMaxXMap.get(y)[0] = Math.min(yMinMaxXMap.get(y)[0], x);
            yMinMaxXMap.get(y)[1] = Math.max(yMinMaxXMap.get(y)[1], x);

            // update col minY and maxY
            xMinMaxYMap.get(x)[0] = Math.min(xMinMaxYMap.get(x)[0], y);
            xMinMaxYMap.get(x)[1] = Math.max(xMinMaxYMap.get(x)[1], y);
        }

        // step 2 - count covered buildings
        int coveredCount = 0;
        for (int[] building : buildings) {
            int x = building[0];
            int y = building[1];

            int[] row = yMinMaxXMap.get(y);
            int[] col = xMinMaxYMap.get(x);

            // step 3 - check if building is covered
            boolean left = row[0] < x;
            boolean right = row[1] > x;
            boolean down = col[0] < y;
            boolean up = col[1] > y;
            
            // step 4 - count covered buildings
            if (left && right && down && up) {
                coveredCount++;
            }
        }

        // step 5 - return the count of covered buildings
        return coveredCount;
    }

    public static void main(String[] args) {
        // int n = 3;
        // int[][] buildings = {{1,2}, {2,2}, {3,2}, {2,1}, {2,3}};
        
        // int n = 3;
        // int[][] buildings = {{1,1}, {1,2}, {2,1}, {2,2}};
        
        int n = 5;
        int[][] buildings = {{1,3}, {3,2}, {3,3}, {3,5}, {5,3}};
        System.out.println(countCoveredBuildings(n, buildings)); 
    }
}


// Problem link - https://leetcode.com/problems/count-number-of-trapezoids-ii/

package NumberTheory_Problems;

import java.util.*;

public class CountNumberOfTrapezoidsII {
    public static int countTrapezoids(int[][] points) {
        int n = points.length;
        
        // Map: slope -> list of intercepts
        Map<Double, List<Double>> slopeIntercepts = new HashMap<>();
        
        // Map: midpoint hash -> list of slopes (for parallelogram detection)
        Map<Integer, List<Double>> midPointsMap = new HashMap<>();
        
        int res = 0;
        
        // step 1: generate all line segments from pairs of points
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                int dx = x2 - x1;
                int dy = y2 - y1;
                
                double slope, intercept;
                
                // handle vertical lines (undefined slope)
                if (dx == 0) {
                    // large number as "infinity"
                    slope = 1e9 + 7; 
                    
                    // x-coordinate as intercept
                    intercept = x1;    
                } else {
                    // calculate slope and intercept
                    slope = (double) dy / dx;
                    intercept = (double) (y1 * dx - x1 * dy) / dx;
                }

                // normalize negative zero
                if (slope == -0.0) slope = 0.0;
                if (intercept == -0.0) intercept = 0.0;
                
                // create unique hash for midpoint
                int midPointKey = (x1 + x2) * 10000 + (y1 + y2);
                
                // store segment information
                slopeIntercepts.computeIfAbsent(slope, k -> new ArrayList<>()).add(intercept);
                midPointsMap.computeIfAbsent(midPointKey, k -> new ArrayList<>()).add(slope);
            }
        }
        
        // step 2: count quadrilaterals with at least one pair of parallel sides
        for (List<Double> intercepts : slopeIntercepts.values()) {
            if (intercepts.size() <= 1) continue;
            
            // count segments on each parallel line
            Map<Double, Integer> interceptCount = new TreeMap<>();
            for (double intercept : intercepts) {
                interceptCount.put(intercept, interceptCount.getOrDefault(intercept, 0) + 1);
            }
            
            // combinatorial counting
            int prevTotal = 0;
            for (int count : interceptCount.values()) {
                res += count * prevTotal;
                prevTotal += count;
            }
        }
        
        // step 3: subtract parallelograms
        for (List<Double> slopes : midPointsMap.values()) {
            if (slopes.size() <= 1) continue;
            
            // count segments by slope
            Map<Double, Integer> slopeCount = new TreeMap<>();
            for (double slope : slopes) {
                slopeCount.put(slope, slopeCount.getOrDefault(slope, 0) + 1);
            }
            
            // remove parallelogram combinations
            int prevTotal = 0;
            for (int count : slopeCount.values()) {
                res -= count * prevTotal;
                prevTotal += count;
            }
        }

        // step 4 - return fianl result, `res`
        return res;
    }

    public static void main(String[] args) {
        // int[][] points = {{-3,2},{3,0},{2,3},{3,2},{2,-3}};

        int[][] points = {{0,0},{1,0},{0,1},{2,1}};
        System.out.println(countTrapezoids(points));
    }
}


// Problem link - https://leetcode.com/problems/block-placement-queries/?envType=daily-question&envId=2026-05-30

package Segment_Tree_problems;

import java.util.*;

public class BlockPlacementQueries {
    public List<Boolean> getResults(int[][] queries) {
        // keep track of final result for each type-2 query
        List<Boolean> res = new ArrayList<>();

        // using ordered set to keep track of occupied positions after type-1 queries
        TreeSet<Integer> st = new TreeSet<>();

        // step 1 - iterate on each query
        for (int[] query : queries) {
            if (query[0] == 1) {
                // type-1 query: place a block at position query[1]
                st.add(query[1]);
            } else {
                // type-2 query: check if there exists a free segment of length sz
                int x = query[1];
                int sz = query[2];

                // prev marks the end of the previous occupied position (or start 0)
                int prev = 0;

                // keep track whether a free segment of required length has been found
                boolean found = false;

                // step 2 - scan occupied positions in sorted order up to x
                for (int curr : st) {
                    if (curr > x) {
                        // no need to consider positions beyond x
                        break;
                    }

                    // step 3 - check if the gap between prev and curr can fit sz blocks
                    if (curr - prev >= sz) {
                        // answer is true
                        found = true;
                        break;
                    }

                    prev = curr;
                }

                // step 4 - also check the last gap from the final occupied position to x
                if (!found) {
                    found = x - prev >= sz;
                }

                // store true or false on the basis of space found
                res.add(found);
            }
        }

        // step 5 - return final result, res
        return res;
    }

    public static void main(String[] args) {
        int[][] queries = {{1,2},{2,3,3},{2,3,1},{2,2,2}};
        BlockPlacementQueries obj = new BlockPlacementQueries();
        List<Boolean> res = obj.getResults(queries);
        System.out.println(res);
    }
}

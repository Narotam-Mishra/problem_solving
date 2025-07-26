
// Problem link - https://leetcode.com/problems/find-indices-of-stable-mountains/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class FindIndicesOfStableMountains {
    public static List<Integer> stableMountains(int[] height, int threshold) {
        // store stable mountain indices in `stableMountains`
        List<Integer> stableMountains = new ArrayList<>();

        // step 1 - start from index 1 since mountain 0 cannot be stable
        // as no mountain exists before index 0
        for (int i = 1; i < height.length; i++) {
            // step 2 - check if the previous mountain is stable
            if (height[i - 1] > threshold) {
                // step 3 - add current mountain's index to result
                stableMountains.add(i);
            }
        }

        // step 4 - return stable mountain indices
        return stableMountains;
    }

    public static void main(String[] args) {
        // int[] height = {1,2,3,4,5};
        // int threshold = 2;

        // int[] height = {10,1,10,1,10};
        // int threshold = 3;

        int[] height = {10,1,10,1,10};
        int threshold = 10;
        List<Integer> res = stableMountains(height, threshold);
        System.out.println(res);
    }
}

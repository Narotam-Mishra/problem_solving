
// Problem link - https://leetcode.com/problems/height-checker/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.Arrays;

public class HeightChecker {
    public static int heightChecker(int[] heights) {
        // step 1 - create a sorted version of the heights array to get the expected order
        int[] expected = Arrays.copyOf(heights, heights.length);
        Arrays.sort(expected);

        // step 2 - iterate on each array's elements and 
        int count = 0;
        for(int i=0; i<heights.length; i++){
            // step 3 - count the number of indices where heights[i] != expected[i]
            if(expected[i] != heights[i]){
                count++;
            }
        }

        // step 4 - return count
        return count;
    }

    public static void main(String[] args) {
        // int[] heights = {1,1,4,2,1,3};

        // int[] heights = {5,1,2,3,4};

        int[] heights = {1,2,3,4,5};
        System.out.println(heightChecker(heights));
    }
}
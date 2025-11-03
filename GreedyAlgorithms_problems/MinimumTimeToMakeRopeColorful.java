
// Problem link - https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2025-11-03

package GreedyAlgorithms_problems;

public class MinimumTimeToMakeRopeColorful {
    public static int minCost(String colors, int[] neededTime) {
        int n = colors.length();

        int minTime = 0;
        int prevMax = 0;

        for (int i = 0; i < n; i++) {
            // for new balloon
            if (i > 0 && colors.charAt(i) != colors.charAt(i-1)) {
                prevMax = 0;
            }

            int curr = neededTime[i];

            minTime += Math.min(prevMax, curr);

            prevMax = Math.max(prevMax, curr);
        }

        return minTime;
    }

    public static void main(String[] args) {
        // String colors = "abaac"; 
        // int[] neededTime = {1,2,3,4,5};

        String colors = "abc"; 
        int[] neededTime = {1,2,3};
        System.out.println(minCost(colors, neededTime));
    }
}
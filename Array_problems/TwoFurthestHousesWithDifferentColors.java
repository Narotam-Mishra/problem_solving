
// Problem link - https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/?envType=daily-question&envId=2026-04-20

package Array_problems;

public class TwoFurthestHousesWithDifferentColors {
    public int maxDistance(int[] colors) {
        // find size of `colors`
        int n = colors.length;

        // keep track of maximum distance
        int maxDis = 0;

        // step 1 - iterate on colors
        for (int i = 0; i < n; i++) {
            // step 2 - find and updated maximum distance from forward side
            if (colors[i] != colors[0]) {
                maxDis = Math.max(maxDis, i);
            }

            // step 3 - find and updated maximum distance from backward side
            if (colors[i] != colors[n - 1]) {
                maxDis = Math.max(maxDis, Math.abs(i - (n - 1)));
            }
        }

        // step 4 - return maximum distance
        return maxDis;
    }

    public static void main(String[] args) {
        int[] colors = {1,1,1,6,1,1,1};
        TwoFurthestHousesWithDifferentColors obj = new TwoFurthestHousesWithDifferentColors();
        System.out.println(obj.maxDistance(colors));
    }
}

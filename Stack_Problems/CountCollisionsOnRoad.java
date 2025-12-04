
// Problem link - https://leetcode.com/problems/count-collisions-on-a-road/?envType=daily-question&envId=2025-12-04

package Stack_Problems;

public class CountCollisionsOnRoad {
    public static  int countCollisions(String directions) {
        int n = directions.length();

        // step 1 - define left & right boundary
        int i = 0;
        while (i < n && directions.charAt(i) == 'L') {
            i++;
        }

        // right boundary
        int j = n - 1;
        while (j >= 0 && directions.charAt(j) == 'R') {
            j--;
        }

        // step 2 - count collisions
        int collisons = 0;
        while (i <= j) {
            if (directions.charAt(i) != 'S') {
                collisons++;
            }
            i++;
        }

        // step 3 - return number of collisons
        return collisons;
    }

    public static void main(String[] args) {
        // String directions = "RLRSLL";

        String directions = "LLRR";
        System.out.println(countCollisions(directions));
    }
}

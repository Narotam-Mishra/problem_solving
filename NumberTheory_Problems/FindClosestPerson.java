
// Problem link - https://leetcode.com/problems/find-closest-person/description/?envType=daily-question&envId=2025-09-04

package NumberTheory_Problems;

public class FindClosestPerson {
    public static int findClosest(int x, int y, int z) {
        // step 1 - find absolute difference (distance)
        // between `x` & `z` and `y` & `z`
        int distX = Math.abs(z - x);
        int distY = Math.abs(z - y);

        // step 2 - compare each speed and return
        if (distX < distY) {
            return 1;
        } else if (distY < distX) {
            return 2;
        } else {
            return 0;
        }
    }

    public static void main(String[] args) {
        // int x = 2, y = 7, z = 4;

        // int x = 2, y = 5, z = 6;

        int x = 1, y = 5, z = 3;
        System.out.println(findClosest(x, y, z));
    }
}

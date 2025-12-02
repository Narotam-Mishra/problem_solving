
// Problem link - https://leetcode.com/problems/count-number-of-trapezoids-i/?envType=daily-question&envId=2025-12-02

package NumberTheory_Problems;

public class CountNumberOfTrapezoids {
    public static int countTrapezoids(int[][] points) {
        long mod = (long)1e9 + 7;

        // step 1 - count horizontal lines
        java.util.Map<Integer, Integer> mp = new java.util.HashMap<>();
        for (int[] p : points) {
            int y = p[1];
            mp.put(y, mp.getOrDefault(y, 0) + 1);
        }

        // step 2 - count trapezoids
        long res = 0, prevHl = 0;

        for (int count : mp.values()) {
            long hLines = (long)count * (count - 1) / 2;  // nC2

            res = (res + (hLines % mod) * (prevHl % mod)) % mod;

            prevHl = (prevHl + hLines) % mod;
        }

        // step 3 - return final result, `res`
        return (int)(res % mod);
    }

    public static void main(String[] args) {
        int[][] points = {{1,0},{2,0},{3,0},{2,2},{3,2}};
        System.out.println(countTrapezoids(points));
    }
}

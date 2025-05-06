
// Problem link - https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/?envType=problem-list-v2&envId=string

package string_problems;

public class ShortestDistanceToTargetStringInCircularArray {
    public static int closestTarget(String[] words, String target, int startIndex) {
        // step 1 - initialize variable to find minimum distance `minDistance`
        int minDistance = Integer.MAX_VALUE;
        int n = words.length;

        // step 2 - iterate on each word of `words` array
        for (int i = 0; i < n; i++) {
            // if target is found
            if (words[i].equals(target)) {
                // step 3 - calculate forward distance
                int forwardDistance = (i - startIndex + n) % n;

                // step 4 - calculate backward distance
                int backwardDistance = (startIndex - i + n) % n;

                // step 5 - find minimum distance from forward and backward distance
                int distance = Math.min(forwardDistance, backwardDistance);

                // update minimum distance
                minDistance = Math.min(distance, minDistance);
            }
        }

        // step 6 - return minimum distance
        return minDistance == Integer.MAX_VALUE ? -1 : minDistance;
    }

    public static void main(String[] args) {
        String[] words = {"hello","i","am","leetcode","hello"};
        String target = "hello";
        int startIndex = 1;

        // String[] words = {"a","b","leetcode"};
        // String target = "leetcode";
        // int startIndex = 0;

        // String[] words = {"i","eat","leetcode"};
        // String target = "ate";
        // int startIndex = 0;
        System.out.println(closestTarget(words, target, startIndex));
    }
}
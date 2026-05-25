
// Problem link - https://leetcode.com/problems/jump-game-vii/?envType=daily-question&envId=2026-05-25

package sliding_window_problems;

public class JumpGameVII {
    public boolean canReach(String s, int minJump, int maxJump) {
        // get the length of the string
        int n = s.length();

        // reachable[i] == 1 means index i is reachable from start under constraints
        int[] reachable = new int[n];

        // starting index is reachable if it's '0'
        reachable[0] = 1;

        // keep track of number of reachable positions in the sliding window
        int windowReachableCount = 0;

        // step 1 - iterate through each index
        for (int j = 1; j <= n - 1; j++) {
            // step 2 - include new index that enters the window on the left: j - minJump
            if (j - minJump >= 0) {
                windowReachableCount += reachable[j - minJump];
            }

            // step 3 - exclude index that leaves the window on the right: j - maxJump - 1
            if (j - maxJump - 1 >= 0) {
                windowReachableCount -= reachable[j - maxJump - 1];
            }

            // step 4 - current position j is reachable if there's at least one reachable
            // index
            if (windowReachableCount > 0 && s.charAt(j) == '0') {
                reachable[j] = 1;
            }
        }

        // step 5 - return true index (n-1) is reachable
        return reachable[n - 1] > 0;
    }

    public static void main(String[] args) {
        String s = "011010";
        int minJump = 2, maxJump = 3;
        JumpGameVII obj = new JumpGameVII();
        System.out.println(obj.canReach(s, minJump, maxJump));
    }
}


// Problem link - https://leetcode.com/problems/jump-game-iii/description/?envType=daily-question&envId=2026-05-17

package Array_problems;

public class JumpGameIII {
    int n;

    private boolean dfsHelper(int[] arr, int i){
        // base case 1 - check for invalid index
        // check if we already visited
        if(i < 0 || i >= n || arr[i] < 0){
            return false;
        }

        // base case 2 - check if we reach 0 then return true
        if(arr[i] == 0) return true;

        // mark visited by negating the value to prevent revisiting
        arr[i] *= -1;

        // recursive case: try jumping in both directions (forward and backward)
        // rightPath: jump forward by `i + arr[i]` steps
        // leftPath: jump backward by `i - arr[i]` steps
        boolean leftPath = dfsHelper(arr, i - arr[i]);
        boolean rightPath = dfsHelper(arr, i + arr[i]);

        // return true if we 0 from either path
        return leftPath || rightPath;
    }

    public boolean canReach(int[] arr, int start) {
        // find size of `arr`
        n = arr.length;

        // step 1 - solve recursively and return
        return dfsHelper(arr, start);
    }

    public static void main(String[] args) {
        int[] arr = {4,2,3,0,3,1,2};
        int start = 5;
        JumpGameIII obj = new JumpGameIII();
        System.out.println(obj.canReach(arr, start));
    }
}

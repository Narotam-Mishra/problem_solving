
// Problem link - https://leetcode.com/problems/find-if-digit-game-can-be-won/description/?envType=problem-list-v2&envId=array

package Array_problems;

public class FindIfDigitGameCanBeWon {
    public static boolean canAliceWin(int[] nums) {
        // store single digit and double digits sum
        int sdSum = 0, ddSum = 0;

        // step 1 - iterate on each number of `nums`
        for (int num : nums) {
            if (num < 10) {
                // find single digit number sum
                sdSum += num;
            } else {
                // find doubel digit number sum
                ddSum += num;
            }
        }

        // step 2 - Alice wins if the sums are different (she picks the larger one)
        return sdSum != ddSum;
    }

    public static void main(String[] args) {
        // int[] nums = {1,2,3,4,10};

        // int[] nums = {1,2,3,4,5,14};

        int[] nums = {5,5,5,25};
        System.out.println(canAliceWin(nums));
    }
}
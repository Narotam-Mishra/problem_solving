
// Problem link - https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/description/?envType=problem-list-v2&envId=string

package string_problems;

public class MinimumNumberOfChairsInWaitingRoom {
    public static int minimumChairs(String s) {
        // step 1 - intialize all necessary variables
        int currentOccupancy = 0;
        int maxNumberOfChairs = 0;

        // step 2 - iterate on each character of input `s`
        for (char ch : s.toCharArray()) {
            if (ch == 'E') {
                // step 3 - increment current occupancy for each entry
                currentOccupancy++;

                // step 4 - update max chairs needed if current occupancy exceed
                if (currentOccupancy > maxNumberOfChairs) {
                    maxNumberOfChairs = currentOccupancy;
                }
            } else {
                // step 5 - decrement current occupancy for each leave
                currentOccupancy--;
            }
        }

        // step 6 - return max number of chairs
        return maxNumberOfChairs;
    }

    public static void main(String[] args) {
        // String s = "EEEEEEE";

        // String s = "ELELEEL";

        String s = "ELEELEELLL";
        System.out.println(minimumChairs(s));
    }
}
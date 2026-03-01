
// Problem link - https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/?envType=daily-question&envId=2026-03-01

package BitMasking_Problems;

public class PartitioningIntoMinimumNumberOfDeciBinaryNumbers {
    public static int minPartitions(String n) {
        // keep track of maximum digit in `n`
        int maxDigit = 0;

        // step 1 - iterate on each character
        for(int i=0; i<n.length(); i++){
            // step 2 - change character to digit
            int digit = n.charAt(i) - '0';

            // step 3 - update maximum digit
            maxDigit = Math.max(maxDigit, digit);
        }

        // step 4 - return maximum digit
        return maxDigit;
    }

    public static void main(String[] args) {
        // String n = "32";

        // String n = "82734";

        String n = "27346209830709182346";
        System.out.println(minPartitions(n));
    }
}

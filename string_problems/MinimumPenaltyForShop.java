
// Problem link - https://leetcode.com/problems/minimum-penalty-for-a-shop/description/?envType=daily-question&envId=2025-12-26

package string_problems;

public class MinimumPenaltyForShop {
    public static int bestClosingTime1(String customers) {
        int n = customers.length();

        // keep track of penalty when shop is opened
        int[] prefixN = new int[n + 1];
        prefixN[0] = 0;

        // keep track of penalty when shop is closed
        int[] suffixY = new int[n + 1];
        suffixY[n] = 0;

        // step 1 - fill prefix when shop is opened
        for (int i = 1; i <= n; i++) {
            if (customers.charAt(i - 1) == 'N') {
                prefixN[i] = prefixN[i - 1] + 1;
            } else {
                prefixN[i] = prefixN[i - 1];
            }
        }

        // step 2 - fill suffix when shop is closed
        for (int i = n - 1; i >= 0; i--) {
            if (customers.charAt(i) == 'Y') {
                suffixY[i] = suffixY[i + 1] + 1;
            } else {
                suffixY[i] = suffixY[i + 1];
            }
        }

        // step 3 - calculate minimum penalty in earliest hour
        int minPenalty = Integer.MAX_VALUE;
        int minHour = Integer.MAX_VALUE;
        for (int i = 0; i <= n; i++) {
            int currPenalty = prefixN[i] + suffixY[i];
            if (currPenalty < minPenalty) {
                minPenalty = currPenalty;
                minHour = i;
            }
        }

        // step 4 - return earliest hour
        return minHour;
    }

    public static int bestClosingTime(String customers) {
        int n = customers.length();

        // initially all shops will be closed,
        // so current penalty will be count of `Y`
        int currPenalty = 0;
        for (int j = 0; j < n; j++) {
            if (customers.charAt(j) == 'Y') {
                currPenalty++;
            }
        }

        // keep track of minimum penalty and earlier hour
        int minPenalty = currPenalty;
        int minHour = 0;

        // step 1 - iterate on i-th hour
        for (int i = 0; i < n; i++) {
            // step 2 - calculate penalty for each hour
            if (customers.charAt(i) == 'Y') {
                currPenalty--;
            } else {
                currPenalty++;
            }

            // step 3 - update minimum penalty
            if (currPenalty < minPenalty) {
                minPenalty = currPenalty;

                // update earlier-hour
                minHour = i + 1;
            }
        }

        // step 4 - return the earliest hour at which the shop must be closed
        return minHour;
    }

    public static void main(String[] args) {
        String customers = "YYNY";

        // String customers = "NNNNN";

        // String customers = "YYYY";
        System.out.println(bestClosingTime(customers));
    }
}

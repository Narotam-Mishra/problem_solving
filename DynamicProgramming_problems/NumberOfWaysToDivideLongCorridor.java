
// Problem link - https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/?envType=daily-question&envId=2025-12-14

package DynamicProgramming_problems;

public class NumberOfWaysToDivideLongCorridor {
    public static int numberOfWays(String corridor) {
        // step 1 - find all Seats, `S` indices
        int n = corridor.length();
        int[] seatIndices = new int[n];
        int seatCount = 0;
        for (int i = 0; i < n; i++) {
            if (corridor.charAt(i) == 'S') {
                seatIndices[seatCount++] = i;
            }
        }

        // step 2 - if seatCount is odd or zero, return 0
        if (seatCount == 0 || seatCount % 2 != 0) {
            return 0;
        }

        // step 3 - calculate ways to divide
        long ways = 1;
        int mod = 1_000_000_007;
        int previousSeatIndex = seatIndices[1];
        for (int i = 2; i < seatCount; i+=2){
            // find partitions size between pairs of seats
            int partitionSize = seatIndices[i] - previousSeatIndex;
            
            // update ways
            ways = (ways * partitionSize) % mod;

            // update previousSeatIndex
            previousSeatIndex = seatIndices[i + 1];
        }

        // step 4 - return ways
        return (int) ways;
    }

    public static void main(String[] args) {
        // String corridor = "SSPPSPS";

        // String corridor = "PPSPSP";

        String corridor = "S";
        System.out.println(numberOfWays(corridor));
    }
}

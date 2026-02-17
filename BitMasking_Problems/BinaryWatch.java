
// Problem link - https://leetcode.com/problems/binary-watch/description/?envType=daily-question&envId=2026-02-17

package BitMasking_Problems;

import java.util.*;

public class BinaryWatch {
    public static List<String> readBinaryWatch(int turnedOn) {
        List<String> res = new ArrayList<>();

        // step 1 - iterate hours
        for (int h = 0; h < 12; h++) {

            // step 2 - iterate minutes
            for (int m = 0; m < 60; m++) {

                // step 3 - check total set bits
                if (Integer.bitCount(h) + Integer.bitCount(m) == turnedOn) {

                    // step 4 - format time
                    String minute = (m < 10 ? "0" : "") + m;
                    res.add(h + ":" + minute);
                }
            }
        }

        // step 5 - return final result, `res`
        return res;
    }

    public static void main(String[] args) {
        int turnedOn = 2;
        System.out.println(readBinaryWatch(turnedOn));
    }
}

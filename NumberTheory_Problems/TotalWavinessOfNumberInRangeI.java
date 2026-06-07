
// Problem link - https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/description/?envType=daily-question&envId=2026-06-04

package NumberTheory_Problems;

import java.util.*;

public class TotalWavinessOfNumberInRangeI {
    private int getWaviness(int num){
        // step 1 - extract each digit from num and store into digits
        ArrayList<Integer> digits = new ArrayList<>();
        while(num > 0){
            digits.add(num % 10);
            num = num / 10;
        }

        // step 2 - reverse digits to get original order
        Collections.reverse(digits);

        // find digits size
        int len = digits.size();

        // edge case
        if(len < 3){
            return 0;
        }

        // step 3 - iterate only over middle digits (index 1 to len-2)
        int waviness = 0;
        for(int i=1; i<len-1; i++){
            // extract digit
            int prevDigit = digits.get(i-1);
            int currDigit = digits.get(i);
            int nextDigit = digits.get(i+1);

            // check peak
            boolean isPeak = (currDigit > prevDigit) && (currDigit > nextDigit);

            // check valley
            boolean isValley = (currDigit < prevDigit) && (currDigit < nextDigit);

            // each peak or valley contributes +1 to waviness
            if(isPeak || isValley) waviness++;
        }

        // return waviness count
        return waviness;
    }

    public int totalWaviness(int num1, int num2) {
        // keep track of waviness count
        int wavinessCount = 0;

        // step 1 - iterate through every number in [num1, num2] inclusive
        for(int num=num1; num<=num2; num++){
            // step 2 - find waviness count
            wavinessCount += getWaviness(num);
        }

        // step 3 - return waviness count
        return wavinessCount;
    }

    public static void main(String[] args) {
        int num1 = 120, num2 = 130;
        TotalWavinessOfNumberInRangeI obj = new TotalWavinessOfNumberInRangeI();
        System.out.println(obj.totalWaviness(num1, num2));   
    }
}

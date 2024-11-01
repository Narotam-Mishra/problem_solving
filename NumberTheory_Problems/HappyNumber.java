
// Problem link : https://leetcode.com/problems/happy-number/

package NumberTheory_Problems;

import java.util.*;

public class HappyNumber {
    public static boolean isHappy(int n) {
        // create a set to store visited numbers for cycle detection
        Set<Integer> visited = new HashSet<>();

        // continue process until termination
        while(n != 1 && !visited.contains(n)){
            // add current number to visited set
            visited.add(n);

            // store sum of square of digits in sum
            int sum = 0;

            // calculate sum of squares of digits
            while(n > 0){
                // extract last digit
                int digit = n % 10;

                // square and add to sum
                sum += digit * digit;

                // extract last digit from number 'n'
                n = n/10;
            }

            // update n for next iteration
            n = sum;
        }

        // return true if n reached 1 (happy number), false otherwise
        return n == 1;
    }

    public static void main(String[] args) {
        // int num = 19;

        int num = 2;
        System.out.println(isHappy(num));
    }
}
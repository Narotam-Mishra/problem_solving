
// Problem link : https://leetcode.com/problems/perfect-number/description/

package NumberTheory_Problems;

public class PerfectNumber {
    public static boolean checkPerfectNumber(int num) {
        // edge case: perfect numbers are greater than 1
        if(num <= 1) return false;

        // start 'sum' with 1 as it is a divisor of every number
        int sum = 1;

        // loop from 2 to sqrt(n) to find divisors
        for(int i=2; i<=Math.sqrt(num); i++){
            if(num % i == 0){
                // if i divides n, add i as a divisor
                sum += i;

                // add n/i if it is distinct divisor
                if(i != num/i) sum += num/i;
            }
        }

        // return true if sum equals input number 'num'
        return sum == num;
    }

    public static void main(String[] args) {
        // int num = 6;

        int num = 28;
        System.out.println(checkPerfectNumber(num));
    }
}
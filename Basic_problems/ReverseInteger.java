
// Problem link - https://leetcode.com/problems/reverse-integer/

package Basic_problems;

public class ReverseInteger {
    public static int reverse(int x) {
        // check for negativity of number
        boolean isNegative = x < 0;

        // Using long to handle overflow
        long reversedNum = 0;

        x = Math.abs(x);

        // reverse number logic
        while(x > 0){
            reversedNum = reversedNum * 10 + x % 10;
            x = x / 10;
        }

        // if the number is negative
        if(isNegative) reversedNum *= -1;

        // check for overflow of number
        if(reversedNum < Integer.MIN_VALUE || reversedNum > Integer.MAX_VALUE){
            return 0;
        }

        // return reversed number
        return (int)reversedNum;
    }

    public static void main(String[] args) {
        System.out.println(reverse(123));
        System.out.println(reverse(-123));
        System.out.println(reverse(120));
        System.out.println(reverse(1534236469));
    }
}
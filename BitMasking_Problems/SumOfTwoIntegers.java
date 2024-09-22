
// Problem link - https://leetcode.com/problems/sum-of-two-integers/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class SumOfTwoIntegers {
    public static int getSum(int a, int b) {
        while(b != 0){
            // calculate the carry
            int carry = (a & b) << 1;

            // find sum without carry
            a = a ^ b;

            // assign carry to b and repeat
            b = carry;
        }
        return a;
    }

    public static void main(String[] args) {
        int a = 2, b = 3;
        System.out.println(getSum(a, b));
    }
}
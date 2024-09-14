
// Problem link - https://leetcode.com/problems/add-digits/description/?envType=problem-list-v2&envId=number-theory

package NumberTheory_Problems;

public class AddDigits {

    private static int findDigitsSum(int num){
        int s = 0;
        while(num > 0){
            s += num % 10;
            num = num/10;
        }
        return s;
    }

    public static int addDigits(int num) {
        while(num >= 10){
            num = findDigitsSum(num);
        }
        return num;
    }

    public static void main(String[] args) {
        // int num = 199;

        int num = 38;
        System.out.println(addDigits(num));
    }
}
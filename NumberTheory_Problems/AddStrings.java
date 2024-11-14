package NumberTheory_Problems;

public class AddStrings {
    public static String addStrings(String num1, String num2) {
        // initialize variables 'res' and 'carry' to store the result and the carry
        StringBuilder res = new StringBuilder();
        int carry = 0;

        // initialize pointers for num1 and num2
        int i = num1.length() - 1;
        int j = num2.length() - 1;

        // loop through num1 and num2 from right to left
        while(i>=0 || j>=0){
            // calculate the sum of the current digits and the carry
            int sum = carry;
            if(i >= 0) sum += num1.charAt(i--) - '0';
            if(j >= 0) sum += num2.charAt(j--) - '0';

            // update result 'res' and carry
            res.insert(0, sum%10);
            carry = sum/10;
        }

        // if there's still a carry, add it to the result
        if(carry > 0) res.insert(0, carry);
        return res.toString();
    }

    public static void main(String[] args) {
        // String num1 = "11", num2 = "123";

        // String num1 = "456", num2 = "77";

        String num1 = "0", num2 = "0";
        System.out.println(addStrings(num1, num2));
    }
}
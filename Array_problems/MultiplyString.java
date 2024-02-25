
// Problem link - https://leetcode.com/problems/multiply-strings/description/

package Array_problems;

/**
 * MultiplyString
 */
public class MultiplyString {
    public String multiply(String num1, String num2) {
        int l1 = num1.length();
        int l2 = num2.length();

        // initialize product Array 'productArr'  
        int[] productArr = new int[l1 + l2];

        // now use multiplication algorithm
        for(int i=l1-1; i>=0; i--) {
            for(int j=l2-1; j>=0; j--) {
                // Calculate positions in the product array
                int p1 = i + j;
                int p2 = i + j + 1;

                // Calculate the product of current digits and add to the ongoing sum
                int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                int sum = mul + productArr[p2];

                // update product array and carry over if necessary
                productArr[p1] += (int)sum/10;
                productArr[p2] = sum % 10;
            }
        }

        //Remove leading zeros and append product digits to ansStr
        StringBuilder ansStr = new StringBuilder();
        for(int digit : productArr){
            if(!(ansStr.length() == 0 && digit == 0)){
                ansStr.append(digit);
            }
        }

        return ansStr.length() == 0 ? "0" : ansStr.toString();
    }
}
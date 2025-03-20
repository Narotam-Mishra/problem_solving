
// Problem link - https://leetcode.com/problems/check-balanced-string/description/?envType=problem-list-v2&envId=string

package string_problems;

public class CheckBalancedString {
    public static boolean isBalanced(String num) {
        // step 1 - initialize variables to store even and odd indices sum
        int evenSum = 0, oddSum = 0;

        // step 2 - iterate on `num`
        for(int i=0; i<num.length(); i++){
            // use 1-based indexing
            int index = i+1;
            // check for even index
            if(index % 2 == 0){
                // step 3 - find even index sum
                evenSum += (num.charAt(i) - '0');
            }else{
                // step 4 - find odd index sum
                oddSum += (num.charAt(i) - '0');
            }
        }

        // step 5 - if even index sum equals to odd index sum then return true otherwise false
        return evenSum == oddSum;
    }

    public static void main(String[] args) {
        // String num = "1234";

        String num = "24123";
        System.out.println(isBalanced(num));
    }
}
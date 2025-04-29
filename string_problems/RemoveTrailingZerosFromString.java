
// Problem link - https://leetcode.com/problems/remove-trailing-zeros-from-a-string/description/?envType=problem-list-v2&envId=string

package string_problems;

public class RemoveTrailingZerosFromString {
    public static String removeTrailingZeros(String num) {
        // step 1 - initialize counter to count trailing zeros in `num`
        int countZeros = 0;
        int n = num.length();

        // step 2 - iterate on `num` from backward to find trailing zeros easily
        for(int i=n-1; i>=0; i--){
            // count trailing zeros
            if(num.charAt(i) == '0'){
                countZeros++;
            }else{
                // for non zeros break the loop
                break;
            }
        }

        // step 3 - return substring of `num` after removing trailing zeros
        return num.substring(0, n - countZeros);
    }

    public static void main(String[] args) {
        // String num = "51230100";

        String num = "123";
        System.out.println(removeTrailingZeros(num));
    }
}

// Problem link : https://leetcode.com/problems/largest-3-same-digit-number-in-string/

package string_problems;

public class Largest3SameDigitNumberInString {
    public static String largestGoodInteger(String num) {
        // step 1: define the possible good integers in descending order
        String[] strNums = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};

        // step 2: iterate through the list and check if num contains the current good integer
        for(String strNum : strNums) {
            // step 3: check if the current good integer is a substring of num
            if(num.contains(strNum)){
                // return the first match
                return strNum;
            }
        }
        // step 4: if no good integer is found, return an empty string
        return "";
    }

    public static void main(String[] args) {
        // String num = "6777133339";

        // String num = "2300019";

        String num = "42352338";
        System.out.println(largestGoodInteger(num));
    }
}


// Problem link - https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i/?envType=problem-list-v2&envId=string

package string_problems;

public class CountSubstringssThatSatisfyKConstraintI {
    public static int countKConstraintSubstrings(String s, int k) {
        // step 1 - initialize count to count number of substring that satisfy k-constraint
        int count = 0;

        // step 2 - iterate on input string `s`
        for(int i=0; i<s.length(); i++){
            int zeroCount = 0, oneCount = 0;

            // step 3 - iterate on each substring
            for(int j=i; j<s.length(); j++){
                // update 0's and 1's count
                if(s.charAt(j) == '0') zeroCount++;
                else oneCount++;

                // step 4 - check k-constraint
                if(zeroCount <= k || oneCount <= k){
                    count++;
                }
            }
        }

        // step 5 - return count
        return count;
    }

    public static void main(String[] args) {
        // String s = "10101";
        // int k = 1;

        // String s = "1010101";
        // int k = 2;

        String s = "11111";
        int k = 1;
        System.out.println(countKConstraintSubstrings(s, k));
    }
}

// Problem link - https://leetcode.com/problems/find-the-k-beauty-of-a-number/description/?envType=problem-list-v2&envId=sliding-window

package sliding_window_problems;

public class FindTheKBeautyOfNumber {
    public static int divisorSubstrings(int num, int k) {
        // step 1 - convert number `num` to string for easy iteration
        String numStr = String.valueOf(num);
        int n = numStr.length();

        // check for edge case: if k is larger than the number of digits, no substrings possible
        if(k > n){
            return 0;
        }

        // step 2 - using sliding window approach: check all k-length substrings
        // count k-beauty of num
        int count = 0;
        for(int i=0; i<=n-k; i++){
            // step 3 - extract substring of length k starting at position i
            String subStr = numStr.substring(i, i+k);

            // step 4 - convert substring to integer to check divisibility
            int divisor = Integer.parseInt(subStr);

            // step 5 - check given conditions for k-beauty
            if(divisor != 0 && num % divisor == 0){
                count++;
            }
        }

        // step 6 - return count (num of substring) that satisfy above condition
        return count;
    }

    public static void main(String[] args) {
        // int num = 240, k = 2;

        int num = 430043, k = 2;
        System.out.println(divisorSubstrings(num, k));
    }
}

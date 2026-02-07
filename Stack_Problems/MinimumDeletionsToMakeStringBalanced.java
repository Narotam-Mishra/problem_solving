
// Problem link - https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2026-02-07

package Stack_Problems;

import java.util.Stack;

public class MinimumDeletionsToMakeStringBalanced {
    public static int minimumDeletions1(String s) {
        // keep track of deletion count
        int deletionCount = 0;

        // using stack based approach to perform simulation
        Stack<Character> st = new Stack<>();

        // step 1 - iterate on each character of input string
        for(char ch : s.toCharArray()){
            // step 2 - if stack is empty push character into it
            if(st.empty()){
                st.push(ch);
            }

            // step 3 - check if current char is 'a' and top of stack is 'b'
            else if(ch == 'a' && st.peek() == 'b'){
                // it means we found invalid pair(`b` before `a`)
                // so perform deletion
                deletionCount++;

                // and remove `b` from stack to break pair
                st.pop();
            }

            // step 4 - otherwise it's valid situation
            // (`a` after `a`) or (`b` after `a`) or (`b` after `b`)
            else{
                // so push leto stack
                st.push(ch);
            }
        }

        // step 5 - return minimum deletion required to balance
        return deletionCount;
    }

    public static int minimumDeletions(String s) {
        int n = s.length();

        // keep track of count left 'b' and right 'a' for each character
        int[] leftB = new int[n];
        int[] rightA = new int[n];

        // step 1 - find 'b' count for each character on left
        int bCount = 0;
        for (int i = 0; i < n; i++) {
            leftB[i] = bCount;
            if (s.charAt(i) == 'b') {
                bCount++;
            }
        }

        // step 2 - find 'a' count for each character on right
        int aCount = 0;
        for (int i = n - 1; i >= 0; i--) {
            rightA[i] = aCount;
            if (s.charAt(i) == 'a') {
                aCount++;
            }
        }

        // step 3 - find minimum deletion required to balance
        int deletionCount = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            deletionCount = Math.min(deletionCount, leftB[i] + rightA[i]);
        }

        // step 4 - return minimum deletion count
        return deletionCount;
    }

    public static void main(String[] args) {
        String s = "aababbab";

        // String s = "bbaaaaabb";
        System.out.println(minimumDeletions(s));
    }
}

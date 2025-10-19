
// Problem link - https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/?envType=daily-question&envId=2025-10-19

package string_problems;

import java.util.*;

public class LexicographicallySmallestStringAfterApplyingOperations {
    // utility method to reverse string
    private static void reverse(char[] arr, int start, int end){
        while(start < end){
            char temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    // utility method to rotate string to the RIGHT by b positions
    private static String rotateString(String str, int b){
        int n = str.length();
        char[] chars = str.toCharArray();
        reverse(chars, 0, n-1);
        reverse(chars, 0, b-1);
        reverse(chars, b, n-1);

        return new String(chars);
    }
    public static String findLexSmallestString(String s, int a, int b) {
        // initialize resultant string `res` with the original string
        String res = s;

        // using BFS to explore all paths
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        // step 1 - start BFS from the original string 
        queue.offer(s);
        visited.add(s);

        while(!queue.isEmpty()){
            // step 2 - get current string state from queue
            String currStr = queue.poll();

            // step 3 - update result `res` if current string is
            // lexicographically smaller
            if(currStr.compareTo(res) < 0){
                res = currStr;
            }

            // operation 1 - add operation
            char[] temp = currStr.toCharArray();
            for(int i=1; i<temp.length; i+=2){
                // add 'a' to digit at odd index and cycle back using modulo 10
                temp[i] = (char)(((temp[i] - '0' + a) % 10) + '0');
            }
            String addStr = new String(temp);

            // step 4 - if this state hasn't been visited, add to queue for
            // exploration
            if(!visited.contains(addStr)){
                queue.offer(addStr);
                visited.add(addStr);
            }

            // operation 2 - rotate string to the right by 'b' positions
            String rotateStr = rotateString(currStr, b);
            
            // step 5 - if this state hasn't been visited, add to queue for
            // exploration
            if(!visited.contains(rotateStr)){
                queue.offer(rotateStr);
                visited.add(rotateStr);
            }
        }

        // step 6 - return final result `res`
        return res;
    }

    public static void main(String[] args) {
        // String s = "5525";
        // int a = 9, b = 2;

        // String s = "74";
        // int a = 5, b = 1;

        String s = "0011";
        int a = 4, b = 2;
        System.out.println(findLexSmallestString(s, a, b));
    }
}

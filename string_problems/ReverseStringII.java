
// Problem link : https://leetcode.com/problems/reverse-string-ii/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class ReverseStringII {

    // utility method to reverse string
    private static void reverseString(char[] arr, int l, int r){
        while(l < r){
            char temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    }
    public static String reverseStr(String s, int k) {
        // convert the string to an array for easier manipulation
        char[] strArr = s.toCharArray();
        int n = strArr.length;

        // step 1 - traverse the string in steps of 2k
        for(int i=0; i<n; i+=2*k){
            // step 2 - reverse the first k characters within the current 2k block
            int left = i;
            
            // ensure the right pointer doesn't exceed the string length
            int right = Math.min(i+k-1, n-1);

            // step 3 - reverse the segment using a two-pointer approach
            reverseString(strArr, left, right);
        }

        // step 4 - convert the array back to a string and return the result
        return new String(strArr);
    }

    public static void main(String[] args) {
        // String s = "abcdefg";
        // int k = 2;

        String s = "abcd";
        int k = 2;
        System.out.println(reverseStr(s, k));
    }
}
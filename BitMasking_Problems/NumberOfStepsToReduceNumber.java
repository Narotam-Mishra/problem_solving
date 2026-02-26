
// Problem link - https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2026-02-26

package BitMasking_Problems;

public class NumberOfStepsToReduceNumber {
    private static String addOne(String s) {
        char[] arr = s.toCharArray();
        int i = arr.length - 1;
        
        while (i >= 0 && arr[i] != '0') {
            arr[i] = '0';
            i--;
        }
        if (i < 0) {
            return "1" + new String(arr);
        } else {
            arr[i] = '1';
            return new String(arr);
        }
    }

    public static int numSteps(String s) {
        int steps = 0;

        while(s.length() > 1){
            int n = s.length();
            if(s.charAt(n-1) == '0'){
                s = s.substring(0, n-1);
            }
            else{
                s = addOne(s);
            }
            steps++;
        }

        return steps;
    }

    public static void main(String[] args) {
        String s = "1101";
        System.out.println(numSteps(s));
    }
}

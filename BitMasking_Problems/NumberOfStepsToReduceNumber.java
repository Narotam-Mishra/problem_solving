
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

        // step 1 - iterate on each binary number
        while(s.length() > 1){
            int n = s.length();

            // step 2 - for even number remove LSB
            if(s.charAt(n-1) == '0'){
                s = s.substring(0, n-1);
            }
            // step 3 - for odd number add 1 to i
            else{
                s = addOne(s);
            }
            // step 4 - increment step for each operation
            steps++;
        }

        // step 5 - return number of steps
        return steps;
    }

    public static void main(String[] args) {
        String s = "1101";
        System.out.println(numSteps(s));
    }
}

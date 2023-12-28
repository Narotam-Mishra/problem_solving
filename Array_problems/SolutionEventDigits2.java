
// Problem link - https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/

package Array_problems;

public class SolutionEventDigits2 {
    
    public static int findNumbers(int arr[]){
        int count = 0;

        for(int num : arr){
            if(hasEvenDigit(num)){
                count++;
            }
        }
        return count;
    }

    // function check whether a number contains even digits or not
    public static boolean hasEvenDigit(int num){
        int count = 0;
        while (num>0) {
            num = num/10;
            count++;
        }
        if(count%2 == 0) return true;
        else return false;
    }
}

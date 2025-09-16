
// Problem link - https://leetcode.com/problems/replace-non-coprime-numbers-in-array/?envType=daily-question&envId=2025-09-16

package NumberTheory_Problems;

import java.util.*;

public class ReplaceNonCoprimeNumbersInArray {
    // utility method to find GCD of two numbers
    private static int findGCD(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // utility method to find LCM of two numbers
    private static long findLCM(int a, int b){
        return ((long) a * b) / findGCD(a, b);
    }

    public static List<Integer> replaceNonCoprimes1(int[] nums) {
        // step 1 - create copy of input array `nums` in `res`
        List<Integer> res = new ArrayList<>();
        for(int num : nums){
            res.add(num);
        }

        // pointer to keep track of current position
        int i = 0;

        // step 2 - // Process the array until no more adjacent non-coprime pairs exist
        while(i < res.size() - 1){
            if(findGCD(res.get(i), res.get(i+1)) > 1){
                // step 3 - calculate LCM of the two adjacent numbers
                long lcmValue = findLCM(res.get(i), res.get(i+1));

                // step 4 - remove the two numbers and replace with their LCM
                res.remove(i);
                res.set(i, (int)lcmValue);

                // step 5 - move back one position to check if new LCM
                // creates a non-coprime pair with the previous element
                if(i > 0){
                    i--;
                }
            }else{
                // otherwise, move to next position if current pair is co-prime
                i++;
            }
        }

        // step 6 - return final result `res`
        return res;
    }

    public static List<Integer> replaceNonCoprimes(int[] nums) {
        // store final result in `res` 
        List<Integer> res = new ArrayList<>();

        // step 1 - process the array until no more adjacent non-coprime pairs exist
        for(int num : nums){
            // step 2 - keep merging the current number with the last element in result
            while(!res.isEmpty()){
                int prevNum = res.get(res.size() - 1);
                int currNum = num;

                // as long as they are non-coprime
                int gcdValue = findGCD(prevNum, currNum);
                if(gcdValue == 1){
                    break;
                }

                int lcmValue = prevNum / gcdValue * currNum;

                // step 3 - replace num with LCM of last element and current num
                num = lcmValue;

                // step 4 - remove the last element
                res.remove(res.size() - 1);
            }

            // step 5 - add the (possibly merged) number to result `res`
            res.add(num);
        }

        // step 6 - return final result `res`
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {6,4,3,2,7,6,2};

        // int[] nums = {2,2,1,1,3,3,3};
        List<Integer> res = replaceNonCoprimes(nums);
        System.out.println(res);
    }
}

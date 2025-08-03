
// Problem link - https://leetcode.com/problems/finding-3-digit-even-numbers/description/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class FindingThreeDigitEvenNumbers {
    private static boolean canFormNumber(int[] requiredDigits, Map<Integer, Integer> availableMap){
        // count how many of each digit we need
        Map<Integer, Integer> neededMap = new HashMap<>();
        for(int digit : requiredDigits){
            neededMap.put(digit, neededMap.getOrDefault(digit, 0) + 1);
        }

        // check if we have enough of each required digits
        for(Map.Entry<Integer, Integer> entry : neededMap.entrySet()){
            int digit = entry.getKey();
            int count = entry.getValue();
            int available = availableMap.getOrDefault(digit, 0);
            if(available < count){
                return false;
            }
        }

        return true;
    }
    
    public static int[] findEvenNumbers1(int[] digits) {
        // step 1 - store frequency of each digit in `digitsMap` map
        Map<Integer, Integer> digitsMap = new HashMap<>();
        for(int digit : digits){
            digitsMap.put(digit, digitsMap.getOrDefault(digit, 0) + 1);
        }

        // step 2 - check each possible even 3-digit number from 100 to 999
        List<Integer> validEvenNums = new ArrayList<>();
        for(int num=100; num<=999; num+=2){
            // step 3 - extract each digit from current number
            int hundreads = num / 100;
            int tens = (num % 100) / 10;
            int units = num % 10;

            // step 4 - check if we can form this number from available digits in `digitsMap`
            if(canFormNumber(new int[] {hundreads, tens, units}, digitsMap)){
                validEvenNums.add(num);
            }
        }

        // step 5 - return `validEvenNums` array as it is already sorted
        return validEvenNums.stream().mapToInt(Integer::intValue).toArray();
    }

    public static int[] findEvenNumbers(int[] digits) {
        // step 1 - store frequency of each digit in `digitsMap` map
        int[] counts = new int[10];
        for(int digit : digits){
            counts[digit]++;
        }

        // step 2 - check each possible even 3-digit number from 100 to 999
        List<Integer> validEvenNums = new ArrayList<>();
        for(int num=100; num<=999; num+=2){
            // step 3 - extract each digit from current number
            int hundreds = num / 100;
            int tens = (num % 100) / 10;
            int units = num % 10;

            // step 4 - check if we can form this number from available digits in `digitsMap`
            counts[hundreds]--; 
            counts[tens]--; 
            counts[units]--;
            if(counts[hundreds] >= 0 && counts[tens] >= 0 && counts[units] >= 0){
                // store this number into valid even number array
                validEvenNums.add(num);
            }

            // step 5 - restore the count to check other combination of number
            counts[hundreds]++; 
            counts[tens]++;
            counts[units]++;
        }

        // step 6 - return `validEvenNums` array as it is already sorted
        return validEvenNums.stream().mapToInt(Integer::intValue).toArray();
    }

    public static void main(String[] args) {
        int[] digits = {2,1,3,0};

        // int[] digits = {2,2,8,8,2};

        // int[] digits = {3,7,5};
        int[] res = findEvenNumbers(digits);
        System.out.println(Arrays.toString(res));
    }
}
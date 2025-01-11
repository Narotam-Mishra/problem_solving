
// Problem link : https://leetcode.com/problems/count-largest-group/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class CountLargestGroup {

    // utility method to find digit sum
    private static int getDigitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }
    public static int countLargestGroup(int n) {
        // step 1 - use map to store the size of each digit sum group
        Map<Integer, Integer> digitSumMap = new HashMap<>();

        // step 2 - group numbers by their digit sums
        for(int i=1; i<=n; i++){
            int digitSum = getDigitSum(i);
            digitSumMap.put(digitSum, digitSumMap.getOrDefault(digitSum,0) + 1);
        }

        // step 3 - find the largest group size
        int maxGroupSize = 0;
        for(int size : digitSumMap.values()){
            maxGroupSize = Math.max(maxGroupSize, size);
        }

        // step 4 - count how many groups have the largest size
        int largestGroupCount = 0;
        for(int size : digitSumMap.values()){
            if(size == maxGroupSize) largestGroupCount++;
        }

        // step 5 - return the largest group count
        return largestGroupCount;
    }

    public static void main(String[] args) {
        // int n = 13;

        int n = 2;
        System.out.println(countLargestGroup(n));
    }
}
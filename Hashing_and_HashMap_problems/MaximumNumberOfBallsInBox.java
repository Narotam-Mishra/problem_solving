
// Problem link : https://leetcode.com/problems/maximum-number-of-balls-in-a-box/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

public class MaximumNumberOfBallsInBox {
    // utility method to calculate sum of digits
    private static int findSumOfDigits(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }

    public static int countBalls(int lowLimit, int highLimit) {
        // step 1 - box map array to store the count of balls in each box
        int[] boxMapArr = new int[47];

        // step 2 - iterate through all ball numbers
        for(int i=lowLimit; i<=highLimit; i++){
            int boxNumber = findSumOfDigits(i);

            // update the count in box map array
            boxMapArr[boxNumber]++;
        }

        // step 3 - find the maximum number of balls in any box and return its value
        int maxBalls = 0;
        for(int count : boxMapArr){
            maxBalls = Math.max(maxBalls, count);
        }

        return maxBalls;
    }

    public static void main(String[] args) {
        // int lowLimit = 1, highLimit = 10;

        // int lowLimit = 5, highLimit = 15;

        int lowLimit = 19, highLimit = 28;
        System.out.println(countBalls(lowLimit, highLimit));
    }
}
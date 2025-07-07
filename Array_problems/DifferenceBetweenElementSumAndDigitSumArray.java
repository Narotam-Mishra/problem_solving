package Array_problems;

public class DifferenceBetweenElementSumAndDigitSumArray {
    
    // utlity function to find sum of array's elements digit sum
    private static int findDigitSum(int[] arr) {
        int digitSum = 0;
        for (int num : arr) {
            if (num <= 9) {
                digitSum += num;
            } else {
                while (num > 0) {
                    digitSum += num % 10;
                    num = num / 10;
                }
            }
        }
    return digitSum;
    }

    // utlity function to find sum of array's elements
    private static int findArraySum(int[] arr) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        return sum;
    }

    public static int differenceOfSum(int[] nums) {
        // step 1 - get array's element sum
        int elementSum = findArraySum(nums);

        // step 2 - get array's digit sum
        int digitSum = findDigitSum(nums);

        // step 3 - find and return the absolute difference between the element sum and digit sum
        return Math.abs(elementSum - digitSum);
    }

    public static void main(String[] args) {
        // int[] nums = {1,15,6,3};

        int[] nums = {1,2,3,4};
        System.out.println(differenceOfSum(nums));
    }
}

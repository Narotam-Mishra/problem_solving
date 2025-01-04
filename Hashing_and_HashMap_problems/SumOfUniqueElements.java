package Hashing_and_HashMap_problems;

public class SumOfUniqueElements {
    public static int sumOfUnique(int[] nums) {
        // step 1 - intialize `sum` variable to store unique numbers sum
        int sum = 0;

        // step 2 - create frequency array to count frequency
        int[] freqArr = new int[101];

        // fill frequency
        for (int num : nums) {
            freqArr[num]++;
        }

        // step 3 - iterate over frequency array and add unique numbers to sum
        for (int i = 0; i < freqArr.length; i++) {
            if (freqArr[i] == 1) {
                sum += i;
            }
        }

        // step 4 - return unique numbers sum
        return sum;
    }

    public static void main(String[] args) {
        // int[] nums = { 1, 2, 3, 2 };

        // int[] nums = { 1, 1, 1, 1, 1 };

        int[] nums = { 1, 2, 3, 4, 5 };
        System.out.println(sumOfUnique(nums)); // 4
    }
}
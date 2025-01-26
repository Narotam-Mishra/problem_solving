package Hashing_and_HashMap_problems;

public class CountElementsWithMaximumFrequency {
    public static int maxFrequencyElements(int[] nums) {
        // step 1: create a frquency array map to store the frequency of each element
        int[] freq = new int[101];
        for (int i = 0; i < nums.length; i++) {
            freq[nums[i]]++;
        }

        // step 2: find the maximum frequency
        int maxFreq = 0;
        for (int i = 0; i < freq.length; i++) {
            maxFreq = Math.max(maxFreq, freq[i]);
        }

        // step 3: sum up the frequencies of elements with the maximum frequency
        int totalFrquency = 0;
        for (int i = 0; i < freq.length; i++) {
            if (freq[i] == maxFreq) {
                totalFrquency += freq[i];
            }
        }

        // step 4 : return the total frequency
        return totalFrquency;
    }

    public static void main(String[] args) {
        // int[] nums = {1,2,2,3,1,4};

        // int[] nums = {1,2,3,4,5};

        // int[] nums = {15};

        int[] nums = {81,81,81,81,81,81,81,17,28,81,81,56,81,54,81,81,81,81,81,60,81,28,81,81,81,81,81,54,81,81,81,81,100,28};
        System.out.println(maxFrequencyElements(nums));
    }
}
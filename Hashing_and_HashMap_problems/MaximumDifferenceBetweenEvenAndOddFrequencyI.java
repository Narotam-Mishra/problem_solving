
// Problem link - https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

public class MaximumDifferenceBetweenEvenAndOddFrequencyI {
    public static int maxDifference(String s) {
        // step 1 - create frequency map array and fill it with characters frequencies
        int[] freqArr = new int[26];
        for(char ch : s.toCharArray()){
            int charCode = (ch - 'a');
            freqArr[charCode]++;
        }

        // step 2 - find maximum odd frequency from frequency map array
        int maxOddFreq = 0;
        for(int freq : freqArr){
            if(freq % 2 != 0){
                maxOddFreq = Math.max(maxOddFreq, freq);
            }
        }

        // step 3 - find minimum even frequency from frequency map array
        int minEvenFreq = Integer.MAX_VALUE;
        for(int freq : freqArr){
            if(freq > 0 && freq % 2 == 0){
                minEvenFreq = Math.min(minEvenFreq, freq);
            }
        }
        
        // step 4 - find and return the maximum difference
        return (maxOddFreq - minEvenFreq);
    }

    public static void main(String[] args) {
        // String s = "aaaaabbc";

        String s = "abcabcab";
        System.out.println(maxDifference(s));
    }
}

// Problem link : https://leetcode.com/problems/count-pairs-that-form-a-complete-day-i/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

public class CountPairsThatFromCompleteDayI {
    public static int countCompleteDayPairs(int[] hours) {
        // step 1 - initialize an array to count frequencies of remainders
        int[] freq = new int[24];

        // step 2 - calculate remainders and count their occurrences
        for(int hour : hours){
            int remainder = hour % 24;
            freq[remainder]++;
        }

        // step 3 - count pairs for each remainder
        int pairs = 0;
        for(int r=0; r<=12; r++){
            // special case : remainders 0 and 12 pair with themselves
            if(r==0 || r==12){
                // nc2 pairs
                pairs += (freq[r] * (freq[r]-1)) / 2;
            }else{
                // general case: Pair r with 24 - r
                pairs += freq[r] * freq[24-r];
            }
        }

        // step 4 - return pairs count
        return pairs;
    }

    public static void main(String[] args) {
        // int[] hours = {12,12,30,24,24};

        int[] hours = {72,48,24,3};
        System.out.println(countCompleteDayPairs(hours));
    }
}
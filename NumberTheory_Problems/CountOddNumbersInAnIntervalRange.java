
// Problem link - https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/?envType=daily-question&envId=2025-12-07

package NumberTheory_Problems;

public class CountOddNumbersInAnIntervalRange {
    public static int countOdds(int low, int high) {
        // step 1 - calculate total number in range
        int totalNums = high - low + 1;

        // step 2 - check if low is odd, we need ceiling of (totalNumbers / 2)
        // if low is even, we need floor of (totalNumbers / 2)
        if(low % 2 == 1){
            return (totalNums + 1) / 2;
        }else{
            return totalNums/2;
        }
    }

    public static void main(String[] args) {
        // int low = 3, high = 7;

        int low = 8, high = 10;
        System.out.println(countOdds(low, high));
    }
}

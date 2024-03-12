
// Problem link - https://leetcode.com/problems/guess-number-higher-or-lower/description/

package binarySearch_problems;

public class GuessNumber {
    public int guessNumber(int n) {
        int s = 1, e = n;

        while(s <= e){
            int mid = s + (e - s)/2;
            int res = guess(mid);
            if(res == 0) return mid;
            else if (res == 1){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return s;
    }

    private int guess(int mid) {
        throw new UnsupportedOperationException("Predefined API method as part of problem");
    }
}

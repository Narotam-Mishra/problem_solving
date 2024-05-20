
// Problem link - https://leetcode.com/problems/valid-perfect-square/description/

package BinarySearch_problems;

public class ValidPerfectSquare {
    public boolean isPerfectSquare(int num) {
        long s = 1, e = num;

        while(s <= e){
            long mid = s + (e - s)/2;
            if(mid * mid == num){
                return true;
            }else if(mid * mid < num){
                // discard left half of search space
                s = mid + 1;
            }else{
                // discard right half of search space
                e = mid - 1;
            }
        }
        return false;
    }
}

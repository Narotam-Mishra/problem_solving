
// Problem link - https://leetcode.com/problems/sqrtx/description/

package BinarySearch_problems;

public class Sqrt {
    public int mySqrt(int x) {
        int s = 1, e = x;

        while(s <= e){
            int mid = (s + e)/2;

            if(mid  == x/mid){
                return mid;
            }else if(mid  > x/mid){
                // discard right half if array
                e = mid - 1;
            }else{
                // discard left half of array
                s = mid + 1;
            }
        }
        return e;
    }
}


// Problem link - https://leetcode.com/problems/arranging-coins/description/

package BinarySearch_problems;

public class ArrangeCoins {
    public int arrangeCoins(long n) {
        long s = 1, e = n;
        long ans = 1;

        while (s <= e) {
            long mid = s + (e - s) / 2;
            long val = (mid * (mid + 1)) / 2;

            if (val <= n) {
                // we get the first potential ans in val
                ans = mid;
                // if we find potential ans then we can better ans in right half of array,
                // because we have of find maximum number of i.e k (mid) such k<=n
                // discard left half of array
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return (int)ans;
    }
}

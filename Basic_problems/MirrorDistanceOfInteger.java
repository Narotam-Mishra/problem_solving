
// Problem link - https://leetcode.com/problems/mirror-distance-of-an-integer/?envType=daily-question&envId=2026-04-18

package Basic_problems;

public class MirrorDistanceOfInteger {
    // utility function to reverse a number
    private int reverseNum(int num){
        int rev = 0;
        while(num > 0){
            int rem = num % 10;
            rev = rev*10 + rem;
            num = num / 10;
        }
        return rev;
    }

    public int mirrorDistance(int n) {
        // step 1 - perfrome the given and return result
        return Math.abs(n - reverseNum(n));
    }

    public static void main(String[] args) {
        MirrorDistanceOfInteger obj = new MirrorDistanceOfInteger();
        // int n = 25;

        // int n = 10;

        int n = 7;
        System.out.println(obj.mirrorDistance(n));
    }
}

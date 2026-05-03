
// Problem link - https://leetcode.com/problems/rotated-digits/description/?envType=daily-question&envId=2026-05-02

package NumberTheory_Problems;

public class RotatedDigits {
    // utility method to check if number is good or not
    private boolean  isGoodNumber(int num){
        boolean canChange = false;

        while(num > 0){
            int d = num % 10;

            if(d == 3 || d == 4 || d == 7) return false;

            if(d == 2 || d == 5 || d == 6 || d == 9){
                canChange = true;
            }

            num = num / 10;
        }

        return canChange;
    }

    public int rotatedDigits(int n) {
        // counter to keep track of good integers
        int count = 0;

        // step 1 - iterate of each number from 1 to num
        for(int num=1; num<=n; num++){
            // step 2 - check for good integers
            if(isGoodNumber(num)){
                // increment count
                count++;
            }
        }

        // step 3 - return counter, `count`
        return count;
    }

    public static void main(String[] args) {
        int n = 10;
        RotatedDigits obj = new RotatedDigits();
        System.out.println(obj.rotatedDigits(n));
    }
}

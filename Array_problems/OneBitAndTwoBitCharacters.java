
// Problem link - https://leetcode.com/problems/1-bit-and-2-bit-characters/description/?envType=problem-list-v2&envId=array

package Array_problems;

public class OneBitAndTwoBitCharacters {
    public static boolean isOneBitCharacter(int[] bits) {
        // step 1 - start from the beginning of the array `bits`
        int i = 0;
        
        // step 2 - process each bit unless we reach or pass the last position
        while(i < bits.length - 1){
            // step 3 - if current bit is `0` then it is 1-Bit Character
            if(bits[i] == 0){
                // so move forward by 1-position
                i++;
            // step 4 - otherwise it is 2-Bit Character
            }else{
                // so move forward by 2-positions
                i+=2;
            }
        }
        
        // step 5 - if we landed on last bit position then it is 1-Bit Character, so return true
        // otherwise it is 2-Bits Character, so return false
        return i == bits.length - 1;
    }

    public static void main(String[] args) {
        // int[] bits = {1,0,0};

        int[] bits = {1,1,1,0};
        System.out.println(isOneBitCharacter(bits));
    }
}
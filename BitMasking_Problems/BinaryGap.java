
// Problem link : https://leetcode.com/problems/binary-gap/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class BinaryGap {
    public static int binaryGap(int n) {
        int maxDistance = 0;
        int currPos = 0;
        int lastPos = -1;

        while(n > 0){
            // check if the current bit is 1
            if((n & 1) == 1){
                if(lastPos != -1){
                    // calculate the distance between the current and last 1
                    maxDistance = Math.max(maxDistance, currPos - lastPos);
                }
                // update the position of the last 1
                lastPos = currPos;
            }
            // update current position 'currPos'
            currPos++;
            // shift right to process the next bit
            n = n >> 1;
        }
        // return maximum distance
        return maxDistance;
    }

    public static void main(String[] args) {
        // int num = 22;

        // int num = 8;

        int num = 5;
        System.out.println(binaryGap(num));
    }
}
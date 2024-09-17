
// Problem link : https://leetcode.com/problems/xor-operation-in-an-array/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class XOROperationInArray {
    public static int xorOperation(int n, int start) {
        int xorVal = 0;

        for(int i=0; i<n; i++){
            // calculate running XOR value
            xorVal ^= start + 2 * i;
        }

        // return XOR value 'xorVal'
        return xorVal;
    }

    public static void main(String[] args) {
        // int n = 5, start = 0;

        int n = 4, start = 3;
        System.out.println(xorOperation(n, start));
    }
}
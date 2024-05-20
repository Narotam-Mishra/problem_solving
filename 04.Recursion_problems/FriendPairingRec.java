
// Problem link - https://www.codingninjas.com/studio/problems/friends-pairing-problem_1214625?leftPanelTabValue=PROBLEM


package Recursion_problems;

/**
 * FriendPairingRec
 */
public class FriendPairingRec {
    private static int friendPairing(int n){
        if(n == 1 || n == 2) return n;
        else{
            return (friendPairing(n-1) + ((n-1) * friendPairing(n-2)));
        }
    }
    public static int numberOfWays(int n) {
        return friendPairing(n);
    }

    public static void main(String[] args) {
        int n = 4;
        System.out.println(numberOfWays(n));
    }
}

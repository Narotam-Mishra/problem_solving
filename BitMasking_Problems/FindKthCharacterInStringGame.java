package BitMasking_Problems;

public class FindKthCharacterInStringGame {

    public static char kthCharacter(int k) {
        // get number of set bits in the binary representation of (k - 1)
        int flips = Integer.bitCount(k-1);

        // final character is determined by how many flips (bit counts) have occurred
        // we start with 'a' and move ahead in the alphabet by the number of flips
        return (char)('a' + flips);
    }

    public static char kthCharacter1(int k) {
        String str = "a";
        String res = "";

        res = str;

        // form string as per given condition by using infinite looping
        while(true){
            // iterate over the current string
            for(int i=0; i<str.length(); i++){
                // increment character by 1 and append to res
                res = res + (char)((int)str.charAt(i) + 1);
            }

            // store transformed string to original string
            str = res;
            if(str.length() >= k){
                // stop when length of the string exceeds or equals k
                break;
            }
        }
        // return kth character
        return str.charAt(k-1);
    }

    public static void main(String[] args) {
        // int k = 5;

        // int k = 10;

        int k = 500;
        System.out.println(kthCharacter(k));
    }
}
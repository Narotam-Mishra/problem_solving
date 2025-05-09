package string_problems;

public class MaximumScoreAfterSplittingString {
    public static int maxScore(String s) {
        // step 1 - find count of total ones in `s`
        int totalOnes = 0;
        for(char ch : s.toCharArray()){
            if(ch == '1') totalOnes++;
        }

        // step 2 - store maximum score in mScor
        int mScore = 0;
        int oneCount = totalOnes, zeroCount = 0;

        // step 3 - iterate on each character of binary string `s`
        // go upto s.length - 1 to ensure right substring is not empty
        for(int i=0; i<s.length()-1; i++){
            if(s.charAt(i) == '0'){
                zeroCount++;
            }else{
                oneCount--;
            }

            // step 4 - calculate maximum score `maxScore` on basis of counts of 1's and 0's
            mScore = Math.max(mScore, zeroCount+oneCount);
        }

        // step 5 - return maximum score `maxScore`
        return mScore;
    }

    public static void main(String[] args) {
        // String s = "011101";

        // String s = "00111";

        // String s = "1111";

        String s = "00";
        System.out.println(maxScore(s));
    }
}
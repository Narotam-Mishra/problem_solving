package string_problems;

public class OneStringSwapCanMakeStringsEqual {
    public static boolean areAlmostEqual(String s1, String s2) {
        // step 1 - if the strings are already equal, return true
        if(s1.equals(s2)) return true;

        // step 2 - find mismatched indices
        int[] mistmatches = new int[2];
        int mistmatchCount = 0;

        for(int i=0; i<s1.length(); i++){
            if(s1.charAt(i) != s2.charAt(i)){
                if(mistmatchCount < 2){
                    mistmatches[mistmatchCount] = i;
                }
                mistmatchCount++;

                // edge: if more than 2 mismatches, return false
                if(mistmatchCount > 2) return false;
            }   
        }

        // step 3 - check if exactly two mismatches can be fixed by a swap
        if(mistmatchCount == 2){
            int i = mistmatches[0], j =mistmatches[1];
            return s1.charAt(i) == s2.charAt(j) && s1.charAt(j) == s2.charAt(i);
        }

        // step 4 - 
        return false;
    }

    public static void main(String[] args) {
        // String s1 = "bank", s2 = "kanb";

        // String s1 = "attack", s2 = "defend";

        String s1 = "kelb", s2 = "kelb";
        System.out.println(areAlmostEqual(s1, s2));
    }
}
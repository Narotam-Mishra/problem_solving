package string_problems;

public class CompareVersionNumbers {
    public static int compareVersion(String version1, String version2) {
        // step 1 - split both versions of input strings by dot
        String[] rev1 = version1.split("\\.");
        String[] rev2 = version2.split("\\.");

        // step 2 - find maximum length of input strings
        int maxLen = Math.max(rev1.length, rev2.length);

        // step 3 - find maximum length of input strings
        for(int i=0; i<maxLen; i++){
            // step 4 - get revision at current position, defaulting to "0" if missing
            String strRev1 = i < rev1.length ? rev1[i] : "0";
            String strRev2 = i < rev2.length ? rev2[i] : "0";

            // step 5 - convert string revision to number for easy comparison
            int num1 = Integer.parseInt(strRev1);
            int num2 = Integer.parseInt(strRev2);

            // step 6 - compare the current revision numbers
            if(num1 < num2){
                // case 1 - return -1
                return -1;
            }else if(num1 > num2){
                // case 2 - return 1
                return 1;
            }
        }

        // step 7 - all revisions are equal, so return 0
        return 0;
    }

    public static void main(String[] args) {
        // String version1 = "1.2", version2 = "1.10";

        // String version1 = "1.01", version2 = "1.001";

        String version1 = "1.0", version2 = "1.0.0.0";
        System.out.println(compareVersion(version1, version2));
    }
}


package Array_problems;

import java.util.Arrays;

/**
 * AnagramStrings
 */

public class AnagramStrings {
    public boolean isAnagram(String s, String t) {
        char tempArr1[] = s.toCharArray();
        char tempArr2[] = t.toCharArray();
        Arrays.sort(tempArr1);
        Arrays.sort(tempArr2);
        
        if(Arrays.equals(tempArr1, tempArr2) == true){
            return true;
        }else{
            return false;
        }
    }
}

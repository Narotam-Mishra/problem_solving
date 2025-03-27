
// Problem link - https://leetcode.com/problems/number-of-senior-citizens/description/?envType=problem-list-v2&envId=string

package string_problems;

public class NumberOfSeniorCitizens {
    public static int countSeniors(String[] details) {
        // step 1 - initialize count
        int count = 0;

        // step 2 - iterate on each detail
        for(String data : details){
            // extract age from detail
            int age = Integer.parseInt(data.substring(11,13));
            
            // step 3 - check if age is greater than 60
            if(age > 60){
                // increment count
                count++;
            }
        }

        // step 4 - return count
        return count;
    }

    public static void main(String[] args) {
        // String[] details = {"7868190130M7522","5303914400F9211","9273338290F4010"};
        
        String[] details = {"1313579440F2036","2921522980M5644"};
        System.out.println(countSeniors(details));
    }
}
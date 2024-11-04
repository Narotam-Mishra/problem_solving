
// Problem link : https://leetcode.com/problems/convert-date-to-binary/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class ConvertDateToBinary {
    public static String convertDateToBinary(String date) {
        // split the date string by hyphens
        String[] dateArr = date.split("-");

        // use a string builder to store the binary components
        StringBuilder res = new StringBuilder();

        // convert each part to binary and append with "-"
        for(int i=0; i<dateArr.length; i++) {
            int part = Integer.parseInt(dateArr[i]);
            res.append(Integer.toBinaryString(part));

            // appeand '-' if it is not the last component
            if(i < dateArr.length - 1){
                res.append("-");
            }
        }

        // return result 'res'
        return res.toString();
    }

    public static void main(String[] args) {
        // String date = "1900-01-01";

        String date = "2080-02-29";
        System.out.println(convertDateToBinary(date));
    }
}
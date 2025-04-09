
// Problem link - https://leetcode.com/problems/defanging-an-ip-address/description/?envType=problem-list-v2&envId=string

package string_problems;

public class DefangingAnIPAddress {
    public static String defangIPaddr(String address) {
        return address.replace(".", "[.]");
    }

    public static void main(String[] args) {
        // String address = "1.1.1.1";

        String address = "255.100.50.0";
        System.out.println(defangIPaddr(address));
    }
}
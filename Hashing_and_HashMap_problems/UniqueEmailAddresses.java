
// Problem link - https://leetcode.com/problems/unique-email-addresses/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class UniqueEmailAddresses {
    public static int numUniqueEmails(String[] emails) {
        // step 1 - create a set to store unique emails
        Set<String> uniqueEmails = new HashSet<>();

        // step 2 - iterate over the emails
        for (String email : emails) {
            // step 3 - split the email into local name and domain name
            String[] parts = email.split("@");
            String localName = parts[0];
            String domainName = parts[1];

            // step 4 - process the local name
            StringBuilder sb = new StringBuilder();
            for (char ch : localName.toCharArray()) {
                // ignore the '.' and everything after '+'
                if (ch == '.') {
                    continue;
                } else if (ch == '+') {
                    break;
                } else {
                    sb.append(ch);
                }
            }

            // step 5 - add the processed email to the set
            uniqueEmails.add(sb.toString() + "@" + domainName);
        }

        // step 6 - return the size of the set
        return uniqueEmails.size();
    }

    public static void main(String[] args) {
        // String[] emails = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
        
        String[] emails = {"a@leetcode.com","b@leetcode.com","c@leetcode.com"};
        System.out.println(numUniqueEmails(emails));
    }
}
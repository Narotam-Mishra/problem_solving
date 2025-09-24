
// Problem link - https://leetcode.com/problems/fraction-to-recurring-decimal/?envType=daily-question&envId=2025-09-24

package NumberTheory_Problems;

import java.util.*;

public class FractionToRecurringDecimal {
    public static String fractionToDecimal(int numerator, int denominator) {
        // Handle zero numerator - always results in "0"
        if (numerator == 0) return "0";
        
        StringBuilder result = new StringBuilder();
        
        // Check if result should be negative
        // XOR logic: negative if exactly one of numerator/denominator is negative
        if ((numerator < 0) ^ (denominator < 0)) {
            result.append("-");
        }
        
        // Use absolute values to avoid overflow issues
        long absNum = Math.abs((long) numerator);
        long absDen = Math.abs((long) denominator);
        
        // Calculate integer part of the division
        long integerPart = absNum / absDen;
        result.append(integerPart);
        
        // Calculate remainder after integer division
        long remainder = absNum % absDen;
        
        // If no remainder, we have a whole number
        if (remainder == 0) return result.toString();
        
        // Add decimal point since we have fractional part
        result.append(".");
        
        // Map to track when we've seen a remainder before (indicates repeating cycle)
        // Key: remainder value, Value: position in result string where this remainder occurred
        Map<Long, Integer> remainderPositions = new HashMap<>();
        
        // Perform long division to get decimal digits
        while (remainder != 0) {
            // If we've seen this remainder before, we found a repeating cycle
            if (remainderPositions.containsKey(remainder)) {
                // Insert opening parenthesis at the position where cycle started
                int cycleStart = remainderPositions.get(remainder);
                result.insert(cycleStart, "(");
                // Add closing parenthesis at the end
                result.append(")");
                break;
            }
            
            // Record this remainder and its position in the result
            remainderPositions.put(remainder, result.length());
            
            // Standard long division: multiply remainder by 10
            remainder *= 10;
            
            // Get next digit
            long digit = remainder / absDen;
            result.append(digit);
            
            // Update remainder for next iteration
            remainder = remainder % absDen;
        }

        // return final result `res`
        return result.toString();
    }

    public static void main(String[] args) {
        // int numerator = 1, denominator = 2;

        // int numerator = 2, denominator = 1;

        int numerator = 4, denominator = 333;
        System.out.println(fractionToDecimal(numerator, denominator));
    }
}

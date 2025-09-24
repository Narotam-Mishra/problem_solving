
// Problem link - https://leetcode.com/problems/fraction-to-recurring-decimal/?envType=daily-question&envId=2025-09-24

let fractionToDecimal = function(numerator, denominator) {
    // handle zero numerator - always results in "0"
    if (numerator === 0) return "0";
    
    let result = "";
    
    // check if result should be negative
    if ((numerator < 0) !== (denominator < 0)) {
        result += "-";
    }
    
    // use absolute values to avoid overflow issues
    let absNum = Math.abs(numerator);
    let absDen = Math.abs(denominator);
    
    // calculate integer part of the division
    let integerPart = Math.floor(absNum / absDen);
    result += integerPart.toString();
    
    // calculate remainder after integer division
    let remainder = absNum % absDen;
    
    // if no remainder, we have a whole number
    if (remainder === 0) return result;
    
    // Add decimal point since we have fractional part
    result += ".";
    
    // map to track when we've seen a remainder before (indicates repeating cycle)
    // Key: remainder value, Value: position in result string where this remainder occurred
    const remainderPositions = new Map();
    
    // perform long division to get decimal digits
    while (remainder !== 0) {
        // if we've seen this remainder before, we found a repeating cycle
        if (remainderPositions.has(remainder)) {
            // insert opening parenthesis at the position where cycle started
            const cycleStart = remainderPositions.get(remainder);
            result = result.slice(0, cycleStart) + "(" + result.slice(cycleStart) + ")";
            break;
        }
        
        // record this remainder and its position in the result
        remainderPositions.set(remainder, result.length);
        
        // standard long division: multiply remainder by 10
        remainder *= 10;
        
        // get next digit
        const digit = Math.floor(remainder / absDen);
        result += digit.toString();
        
        // update remainder for next iteration
        remainder = remainder % absDen;
    }
    
    // return final result `res`
    return result;
};

// const numerator = 1, denominator = 2;

// const numerator = 2, denominator = 1;

const numerator = 4, denominator = 333;
console.log(fractionToDecimal(numerator, denominator));
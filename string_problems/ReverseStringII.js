
// Problem link : https://leetcode.com/problems/reverse-string-ii/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let reverseStr = function(s, k) {
    const n = s.length;

    // convert the string to an array for easier manipulation
    const strArr = s.split('');

    // step 1 - traverse the string in steps of 2k
    for(let i=0; i<n; i+=2*k){
        // step 2 - reverse the first k characters within the current 2k block
        let left = i;
        
        // step 3 - if fewer than k characters remain, reverse all remaining characters
        let right = Math.min(i+k-1, n-1);

        // step 4 - reverse the segment using a two-pointer approach
        while(left < right){
            [strArr[left], strArr[right]] = [strArr[right], strArr[left]];
            left++;
            right--; 
        }
    }

    // step 5 - convert the array back to a string and return the result
    return strArr.join("");
};

// let str = "abcdefg", k = 2;

let str = "abcd", k = 2;
console.log(reverseStr(str, k));

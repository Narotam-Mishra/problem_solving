
// Problem link : https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75

let reverseVowels = function(s) {
    const vowels = 'aeiouAEIOU';
    let l = 0, r = s.length - 1;

    // convert string to character array
    let chars = s.split('');

    while(l < r){
        // move left pointer until it finds a vowel
        while(l < r && !vowels.includes(chars[l])){
            l++;
        }
        // move right pointer until it finds a vowel
        while(l < r && !vowels.includes(chars[r])){
            r--;
        }
        // swap vowels
        let temp = chars[l];
        chars[l] = chars[r];
        chars[r] = temp;
        l++;
        r--;
    }
    return chars.join('');
};

// let str = "hello";

let str = "leetcode";
console.log(reverseVowels(str));

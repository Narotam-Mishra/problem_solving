
// Problem link - https://leetcode.com/problems/sort-vowels-in-a-string/description/?envType=daily-question&envId=2025-09-11

// Using Brute Force Approach
let sortVowels1 = function(s) {
    // storing vowels in set for O(1) lookup
    const vowelsSet = new Set(['a','e','i','o','u','A','E','I','O','U']);
    
    // store vowels from input string `s`
    const vowels = [];

    // step 1 - iterate on string array to find all vowels
    let strArr = s.split('');
    for(let ch of strArr){
        if(vowelsSet.has(ch)){
            vowels.push(ch);
        }
    }

    // step 2 - sort vowels array
    vowels.sort();

    // step 3 - iterate on string array to find vowels
    let idx = 0;
    for(let i=0; i<strArr.length; i++){
        if(vowelsSet.has(strArr[i])){
            // step 4 - replace vowel with its correct sorted order
            strArr[i] = vowels[idx++];
        }
    }

    // step 5 - convert string array back to string and return
    return strArr.join('');
};

let sortVowels = function(s) {
    // utility function to check if charcater is vowel or not
    function isVowel(ch){
        const vCh = ch.toLowerCase(ch);
        return vCh === 'a' || vCh === 'e' || vCh === 'i' || vCh === 'o' || vCh === 'u';
    }

    // step 1 - count frequency of each vowel in input string `s`
    const vowelMap = new Map();
    for(let ch of s){
        if(isVowel(ch)){
            vowelMap.set(ch, (vowelMap.get(ch) || 0) + 1);
        }
    }

    // step 2 - define vowels in ASCII sorted order
    const vowels = "AEIOUaeiou";

    // pointer to track current position in sorted vowels string
    let j = 0;  

    // step 3 - replace vowels in input string `s` with help of sorted vowels
    // convert string to array for mutability 
    let inputStr = s.split('');      
    for(let i=0; i<inputStr.length; i++){
        if(isVowel(inputStr[i])){
            // find next available vowel in sorted order
            while((vowelMap.get(vowels[j]) || 0) === 0){
                // skip vowels that are not present in input string
                j++;
            }

            // replace current vowel with the smallest available vowel
            inputStr[i] = vowels[j];

            // decrese used vowel count in `vowelMap`
            vowelMap.set(vowels[j], vowelMap.get(vowels[j]) - 1);
        }
    }

    // step 4 - return modified string `s`
    return inputStr.join('');
};

// const s = "lEetcOde";

const s = "lYmpH";
console.log(sortVowels(s));
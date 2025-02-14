
// Problem link - https://leetcode.com/problems/count-vowel-substrings-of-a-string/description/?envType=problem-list-v2&envId=hash-table

let countVowelSubstrings1 = function(word) {
    // step 1 - create vowel set
    const vowelsSet = new Set(['a', 'e', 'i','o','u']);
    let count = 0;
    
    // step 2 - iterate through all possible starting points of substrings
    for(let i=0; i<word.length; i++){
        // skip if the current character is not a vowel
        if(!vowelsSet.has(word[i])) continue;

        // initialize a set to track vowels in the current substring
        const currVowels = new Set();
        
        // step 3 - iterate through all possible ending points of substrings
        for(let j=i; j<word.length; j++){
            // if the current character is not a vowel, break out of the inner loop
            if(!vowelsSet.has(word[j])) break;

            // step 4 - add the current vowel to the set
            currVowels.add(word[j]);

            // step 5 - if all five vowels are present, increment the count
            if(currVowels.size === 5){
                count++;
            }
        }
    }

    // step 6 - return number of vowel substrings count 
    return count;
};

// Approach 2 - Using Sliding Window Approach with Map
let countVowelSubstrings = function(word) {
    // step 1 - create object as map to store the last occurrence index of each vowel
    const obj = {a: -1, e: -1, i: -1, o: -1, u: -1};

    // count variable to tack count of valid vowel substrings
    // with left pointer of window
    let count = 0, left = 0

    // step 2 - get vowels array 
    const vowels = Object.keys(obj);

    // step 3 - iterate the input string `word`
    for(let i=0; i<word.length; i++){
        if(vowels.includes(word[i])){
            // step 4 - update the last occurrence index of the current vowel
            obj[word[i]] = i;

            // step 5 - find the minimum index among the last occurrences of all vowels
            const minIndex = Math.min(...Object.values(obj));

            // step 6 - if all vowels are present in the current window, 
            if(minIndex >= 0 && minIndex >= left){
                // count valid substrings
                count += (minIndex - left) + 1;
            }
        }else{
            // if a non-vowel is encountered, reset the window
            left = i + 1;
        }
    }

    // step 7 - return count
    return count;
};

// const word = "aeiouu";

// const word = "unicornarihan";

const word = "cuaieuouac";
console.log(countVowelSubstrings(word));

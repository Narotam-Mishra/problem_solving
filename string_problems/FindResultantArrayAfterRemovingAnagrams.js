
// Problem link - https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/?envType=daily-question&envId=2025-10-13

let removeAnagrams = function(words) {
    // step 1 - utility function check if two strings are anagram or not
    const isAnagram = (word1, word2) => {
        if(word1.length !== word2.length) return false;

        const sortedWord1 = word1.split('').sort().join('');
        const sortedWord2 = word2.split('').sort().join('');

        return sortedWord1 === sortedWord2;
    }

    // step 2 - start from index `1` as need to check previous index (i-1) as well
    let i = 1;

    // step 3 - iterate on words array
    while(i < words.length){
        // step 4 - check if current word is an anagram of previous word
        if(isAnagram(words[i], words[i-1])){
            // step 5 - remove current word from `words`
            words.splice(i, 1);

            // step 6 - after removal, step back one position (if possible)
            // the word that was at position i+1 is now at position i
            // we need to check if this "new" word at position i is also an anagram of i-1
            if(i > 1){
                i--;
            }
        }
        
        // step 7 - otherwise move to next position
        else{
            i++;
        }
    }

    // step 8 - return final list after modification
    return words;
};

// const words = ["abba","baba","bbaa","cd","cd"];

const words = ["a","b","c","d","e"];
console.log(removeAnagrams(words));
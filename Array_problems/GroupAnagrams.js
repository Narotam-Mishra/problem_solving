
// Problem link - https://leetcode.com/problems/group-anagrams/description/

let groupAnagrams = function(strs) {
    let groupedAnagrams = {};

    // iterate on each word of array of strings
    for(word of strs){
        // Sort the characters of the word to use as a key in the hash map
        let sortedWord = word.split('').sort().join('');

        // If the sorted word is already a key, add the word to its corresponding array
        if(groupedAnagrams[sortedWord]){
            groupedAnagrams[sortedWord].push(word);
        }else{
            // If the key doesn't exist, create a new array with the word
            groupedAnagrams[sortedWord] = [word];
        }
    }

    // console.log(groupedAnagrams);
    return Object.values(groupedAnagrams);
};

let strs = ["eat","tea","tan","ate","nat","bat"];
let ans = groupAnagrams(strs);
console.log(ans);
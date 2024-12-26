
// Problem link : https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=problem-list-v2&envId=string

// helper function to count vowels in a given string
function countVowels(str) {
    const vowelSet = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
    let count = 0;

    // iterate over each character of input string `str`
    for(const ch of str){
        // check if the character is a vowel
        if(vowelSet.has(ch)){
            count++;
        }
    }

    // return vowels count
    return count;
}
let halvesAreAlike1 = function(s) {
    // split the string into two halves
    const n = s.length;

    // first half
    const a = s.substring(0, n/2);

    // second half
    const b = s.substring(n/2);

    // count vowels in each half
    const vowelsInA = countVowels(a);
    const vowelsInB = countVowels(b);

    // compare the number of vowels in both halves
    return vowelsInA === vowelsInB;
};

let halvesAreAlike2 = function(s) {
    // intialize counter to count number of vowels 
    // in first and second half of a input string `s`
    let fvc = svc = 0;
    const n = s.length;
    
    // iterate over first and second half of the input string `s`
    for(let i = 0, j = n/2; i < n/2 && j < n; i++, j++){
        // check for vowels and increment the counter
        if("aeiou".includes(s[i].toLowerCase())) fvc++;
        if("aeiou".includes(s[j].toLowerCase())) svc++;
    }

    // check if count of vowels in first and second half are equal or not
    return fvc === svc;
};

let halvesAreAlike = function(s) {
    // intialize counter to count number of vowels 
    // in first and second half of a input string `s`
    let fvc = svc = 0;
    const n = s.length;
    
    // iterate over the input string `s`
    for(let i=0; i<n; i++) {
        if(i < n/2){
            if(s[i].toLowerCase() === 'a' || s[i].toLowerCase() === 'e' || s[i].toLowerCase() === 'i' || s[i].toLowerCase() === 'o' || s[i].toLowerCase() === 'u')
                fvc++;   
        }else{
            if(s[i].toLowerCase() === 'a' || s[i].toLowerCase() === 'e' || s[i].toLowerCase() === 'i' || s[i].toLowerCase() === 'o' || s[i].toLowerCase() === 'u')
                svc++;
        }
    }

    // check if count of vowels in first and second half are equal or not
    return fvc === svc;
};

const s = "book";

// const s = "textbook";
console.log(halvesAreAlike(s));

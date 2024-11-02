
// Problem link : https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

// utility function to swap characters
function swapItems(arr, s, e){
    let temp = arr[s];
    arr[s] = arr[e];
    arr[e] = temp;
}

// utility function to reverse
function reverseUtil(str){
    let arr = str.split("");
    let s = 0;
    let e = arr.length - 1;
    while(s < e){
        swapItems(arr, s, e);
        s++;
        e--;
    }
    // convert array back to string
    return arr.join('');
}

let reverseWords = function(s) {
    let res = "";

    // split sentence into individual words
    const words = s.split(" ");
    
    // iterate on each word
    for(let i=0; i<words.length; i++){
        // reverse each word and add to result
        res += reverseUtil(words[i]);
        
        // add space between words except after the last word
        if(i < words.length - 1) res += " ";
    }
    return res;
};

let s = "Let's take LeetCode contest";
console.log(reverseWords(s));


// Problem link : https://leetcode.com/problems/length-of-last-word/description/

let lengthOfLastWord = function(s) {
    // split string
    const strArr = s.split(" ");

    // filter out empty string
    const fw = strArr.filter(word => word !== '');

    // find length of last word
    return fw.length === 0 ? 0 : fw[fw.length - 1].length;
};

// let str = "Hello World";

// let str = "   fly me   to   the moon  ";

let str = "luffy is still joyboy";
console.log(lengthOfLastWord(str));

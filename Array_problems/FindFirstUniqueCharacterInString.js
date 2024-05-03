
// Problem link - https://leetcode.com/problems/first-unique-character-in-a-string/description/

let firstUniqChar = function(s) {
    // using object as frequency map
    let strMap = {};
    for(let i=0; i<s.length; i++){
        let char = s[i];
        if(strMap[char]){
            strMap[char] += 1;
        }else{
            strMap[char] = 1;
        }
    }
    
    // check the character which is having frquency 1 and return its index
    for(let i=0; i<s.length; i++){
        let curChar = s.charAt(i);
        if(strMap[curChar] == 1){
            return i;
        }
    }

    return -1;
};

let str = "leetcode";
console.log(firstUniqChar(str));

// Problem link - https://leetcode.com/problems/backspace-string-compare/description/

let backspaceCompare = function(s, t) {
    // used two stacks to manage strings s & t
    let st1 = [], st2 = [];

    // iterate string s
    for(let i=0; i<s.length; i++){
        // if current character is not '#' then push it into stack st1
        if(s[i] !== '#'){
            st1.push(s[i]);
        }else{
            // otherwise pop it from stack st1
            if(st1.length > 0) st1.pop();
        }
    }

    // iterate string t
    for(let i=0; i<t.length; i++){
        // if current character is not '#' then push it into stack st2
        if(t[i] !== '#'){
            st2.push(t[i]);
        }else{
            // otherwise pop it from stack st1
            if(st2.length > 0) st2.pop();
        }
    }
    
    // compare both strings using stack top
    while(st1.length > 0 && st2.length > 0){
        if(st1[st1.length - 1] !== st2[st2.length - 1]) return false;
        st1.pop();
        st2.pop();
    }

    // if both stacks are empty that means both strings are equal 
    // return true
    return (st1.length === 0 && st2.length === 0);
};

// let s = "ab#c", t = "ad#c";

// let s = "ab##", t = "c#d#";

let s = "a#c", t = "b";
console.log(backspaceCompare(s, t));
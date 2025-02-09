
// Problem link : https://leetcode.com/problems/isomorphic-strings/?envType=problem-list-v2&envId=hash-table

let isIsomorphic1 = function(s, t) {
    // edge case: if length of both strings `s` & `t` are different
    // then they are not isomorphic, so return false right away
    if(s.length !== t.length){
        return false;
    }

    // step 1 - create two maps to store the mapping from s to t and t to s
    const sTotMap = {};
    const tTosMap = {};

    // step 2 - iterate through each character of the strings
    // and check for isomorphic behaviour
    for(let i=0; i<s.length; i++){
        let charS = s[i];
        let charT = t[i];

        // check if the current character in `s` is already mapped
        if(sTotMap[charS]){
            // if it is already mapped, it should map to the corresponding character in `t`
            if(sTotMap[charS] !== charT){
                // otherwise return false
                return false;
            }
        }else{
            // if not mapped already, add the mapping from `s` to `t`
            sTotMap[charS] = charT;
        }

        // check if the current character in `t` is already mapped
        if(tTosMap[charT]){
            // if it is already mapped, it should map to the corresponding character in `s`
            if(tTosMap[charT] !== charS){
                // otherwise return false
                return false;
            }
        }else{
            // if not mapped already, add the mapping from `t` to `s`
            tTosMap[charT] = charS;
        }
    }

    // step 3 - if all characters are mapped correctly, the strings are isomorphic and return true
    return true;
};

let isIsomorphic = function(s, t) {
    // edge case: if length of both strings `s` & `t` are different
    // then they are not isomorphic, so return false right away
    if(s.length !== t.length){
        return false;
    }

    // step 1 - create a map to store the mapping from s to t
    const charMap = new Map();
    // step 2 - create a set to track characters in t that have already been mapped
    const charSet = new Set();

    // step 3 - iterate through each character of the strings
    // and check for isomorphic behaviour
    for(let i=0; i<s.length; i++){
        let charS = s[i];
        let charT = t[i];

        // check if the current character in `s` is already mapped
        if(charMap.has(charS)){
            // if it is already mapped, it should map to the corresponding character in `t`
            if(charMap.get(charS) !== charT){
                // otherwise return false
                return false;
            }
        }else{
            // if the character in t has already been used, it cannot be mapped again
            if(charSet.has(charT)){
                return false;
            }

            // add the mapping from s to t
            charMap.set(charS, charT);

            // mark the character in t as used
            charSet.add(charT);
        }
    }

    // step 4 - if all characters are mapped correctly, the strings are isomorphic and return true
    return true;
};

const s = "egg", t = "add";

// const s = "foo", t = "bar";

// const s = "paper", t = "title";
console.log(isIsomorphic(s, t));

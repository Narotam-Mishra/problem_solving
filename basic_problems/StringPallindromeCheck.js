
function isPallindrome(str,len){
    if(len === 0) return false;

    let temStr = "";
    for(let i=len-1; i>=0; i--){
        temStr+= str[i];
    }

    if(str === temStr){
        return true;
    }else {
        return false;
    }
}

// Pallindrome string examples - madam, racecar 

let str = "madam";
console.log(isPallindrome(str, str.length));
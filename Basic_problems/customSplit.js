
// create your own split() method which behaves similar to String.split() method

function customSplit(str){
    let result = [];

    for(let i=0; i<str.length; i++){
        result.push(str.charAt(i));
    }

    // push remaining characters
    // result.push(str.substring(startIndex));
    return result;
}

let str = "javascript";
let ans = customSplit(str);
console.log(ans);


// "abc" --> ['a', 'b', 'c']
// Problem 2:

// If +0 and -0 and 0 when used with equality operators always give the ans as true, how can you identify whether the sign of the 0 is + or - ? So write a function that can compare 0 and -0 and if user passes 0 and -0 then it returns false And write function getSign() which takes a number and tells you whether it is pos or neg


// We can differentiate between -0 and 0 using Object.is() method

function isNegativeZero(num){
    return Object.is(num, -0);
}

function compareZero(z1,z2){
    return z1===z2 && isNegativeZero(z1) && isNegativeZero(z2);
}

function getSign(n){
    if (Object.is(n,-0)){
        return 'Negative Zero';
    }else if(n === 0){
        return 'Positive Zero';
    }else if(n > 0){
        return 'Positive Number';
    }else if(n < 0){
        return 'Negative Number';
    }else{
        return 'Not a valid number';
    }
}

console.log(compareZero(-0,-0));
console.log(compareZero(0,-0));

console.log(getSign(-0));
console.log(getSign(0));
console.log(getSign(-2));
console.log(getSign(9));

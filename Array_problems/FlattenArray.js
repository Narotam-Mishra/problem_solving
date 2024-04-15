
// Faltten deeply nested array

// Approach - 1 using Recursion

function flattenArray(arr){
    let res = [];
    arr.forEach(val => {
        if(Array.isArray(val)){
            res.push(...flattenArray(val));
        }else{
            res.push(val);
        }
    });
    return res;
}

// Approach - 2 without Recursion

function flattenArray1(arr){
    let stack = [...arr];
    let res = [];

    while(stack.length){
        let nd = stack.pop();

        if(Array.isArray(nd)){
            stack.push(...nd);
        }else{
            res.unshift(nd);
        }
    }
    return res;
}

let arr = [[1, 2, 3], [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]];
console.log(flattenArray(arr));
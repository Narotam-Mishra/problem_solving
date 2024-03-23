
// Flatten a deeply nested array in JS

/*

Input : [3,2,1,5,[1,4,5],[7,6,8],13]
Output: [3,2,1,5,1,4,5,7,6,8,13]

*/

// Approach - Using recursion
// TC - O(n)

function flattenArray(arr){
    let res = [];
    arr.forEach(item => {
        if(Array.isArray(item)){
            res.push(...flattenArray(item));
        }else{
            res.push(item);
        }
    });
    return res;
}

// Approach - 2 (using Stack)

function flattenArrayUsingStack(arr){
    let flattened = [];
    let stack = [...arr];

    while(stack.length){
        let nextElement = stack.pop();
        if(Array.isArray(nextElement)){
            stack.push(...nextElement);
        }else{
            flattened.unshift(nextElement);
        }
    }
    return flattened;
}

// Approach - 3 (using inbuilt flat method)
const nestedArray = [1, [2, [3, 4], 5], 6];
const flattenedArray = nestedArray.flat(Infinity);
console.log(flattenedArray);


arr = [3,2,1,5,[1,4,5],[7,6,8],13];

// let ans = flattenArray(arr);
let ans1 = flattenArrayUsingStack(arr);

// console.log("Flatten Array:",ans);
console.log("Flatten Array:",ans1);

Array.prototype.customReduce = function(callback, initialVal){
    // check for edge case
    if(this.length === 0 && initialVal === undefined){
        throw TypeError("Reduce of empty array with no initial value");
    }

    let accumulator = initialVal !== undefined ? initialVal : this[0];
    let startIndex = initialVal !== undefined ? 0 : 1;

    for(let i=startIndex; i<this.length; i++){
        accumulator = callback(accumulator,this[i], this, i);
    }

    return accumulator;
}

let arr = [2,3,1,5,4];

let ans = arr.customReduce((acc, curVal) => {
    return acc+curVal;
},0)

console.log(ans);
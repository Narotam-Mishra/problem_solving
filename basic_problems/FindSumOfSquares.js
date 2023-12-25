
let arr = [2,4,5,1,3];

const sum = arr.reduce((acc,sqSum) => {
    return acc + (sqSum*sqSum)
},0);

console.log(sum);
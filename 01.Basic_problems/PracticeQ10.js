
// find output in below code

const arrLike = {
    0:'apple',
    1:'banana',
    2:'cherry',
    length:3
};

const fruits = Array.from(arrLike, (v,i) => (v));
console.log(fruits);
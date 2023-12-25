
const arrLike = { length:5 };

const newArr = Array.from(arrLike, (v,i) => i);
console.log(newArr);
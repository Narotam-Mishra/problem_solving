
//Output -  [[2],[4,6],[8]]

const arr = [[1,2,3], [4,5,6],[7,8,9]];

const res = arr.map(arr => arr.filter(num => num%2==0));
console.log(res);
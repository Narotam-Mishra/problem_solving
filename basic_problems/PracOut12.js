
// Find output of below code 

/*

0
1
2

*/

let count = 0;
setTimeout(() => console.log(count++), 1000);
setTimeout(() => console.log(count++), 2000);
setTimeout(() => console.log(count++), 3000);
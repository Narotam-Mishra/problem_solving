
// Find out of below code

/*

First

*/

let promise1 = Promise.resolve('First');
let promise2 = Promise.resolve('Second');
Promise.race([promise1, promise2]).then(value => console.log(value));
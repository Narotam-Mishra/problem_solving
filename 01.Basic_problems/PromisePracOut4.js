
// Find output of below code

/*

Output - 3

*/

let promise = Promise.resolve(1);
promise.then(value => value + 2).then(value => console.log(value));
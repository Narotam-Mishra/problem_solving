
// Find output of below code

/*


*/

let promise = Promise.resolve(Promise.resolve('Resolve'));
promise.then(res => console.log(res));
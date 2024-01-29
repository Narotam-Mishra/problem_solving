
// Find output of below code

/*

Promise resolved

*/

let promise = new Promise((resolve, reject) => {
    resolve('Promise resolved');
    reject('Promise rejected');
  });
  promise.then(console.log).catch(console.log);
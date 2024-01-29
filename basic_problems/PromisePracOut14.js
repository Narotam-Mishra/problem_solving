
// Find output of below code

/*

Promise 2

*/


Promise.all([
    Promise.resolve('Promise 1'),
    Promise.reject('Promise 2'),
    Promise.resolve('Promise 3')
  ]).then(console.log).catch(console.log);
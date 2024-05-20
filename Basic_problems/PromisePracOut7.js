
// Find output of below code

/*

8

*/


Promise.resolve(2)
  .then(value => value * 2)
  .then(value => Promise.resolve(value * 2))
  .then(value => console.log(value));
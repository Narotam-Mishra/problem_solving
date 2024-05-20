
// Find output of below code

/*

After async function
Done!

*/


async function asyncFunc() {
    let promise = new Promise((resolve, reject) => {
      setTimeout(() => resolve("Done!"), 1000);
    });
    let result = await promise;
    console.log(result);
  }
  asyncFunc();
  console.log("After async function");
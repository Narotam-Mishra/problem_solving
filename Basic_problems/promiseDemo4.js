
// promise example

function createAsyncPromise(){
    return new Promise((resolve,reject) => {
        // async code
        setTimeout(function timerCompleted(){
            // change state of promise
            const value = Math.random();
            if(value < 0.5){
                resolve(value);
            }else{
                reject(value);
            }
        }, 5000);
    });
}

const res = createAsyncPromise();

res.then(
  function fulfilledHandler(value) {
    console.log("promise fulfilled with value:", value);
  },
  function rejectedHandler(value) {
    console.log("promise rejected with value:", value);
  }
);
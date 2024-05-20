
// promise example - 1

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
        }, 3000);
    });
}

const res = createAsyncPromise();
console.log(res);
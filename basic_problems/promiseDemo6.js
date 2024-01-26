
// promise example - 6

function createAsyncPromise(){
    return new Promise((res,rej) => {
        res(101);
    })
}

const res = createAsyncPromise();

for(let i=0; i<10000000000; i++){
    // blocking code....
}

res.then(function fulfilledHandler(value){
    console.log('promise resolved with value:', value);
}, function rejectedHandler(){
    console.log('promise rejected with value', value);
})

for(let i=0; i<100000000000; i++){
    // blocking code....
}

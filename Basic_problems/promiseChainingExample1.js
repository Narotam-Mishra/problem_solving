
// promise chaining example

function createPromiseChain(t){
    return new Promise((res,rej) => {
        setTimeout(() => {
            res(t);
        }, t)
    })
}

const resolver = (val) => {
    console.log('Resolving with value:', val);
}

const rejector = (val) => {
    console.log('Rejecting with value:', val);
}

createPromiseChain(5000) // return promise say pr1 {value: undefined, state: pending, onFulFilled: [f], onRejected: []}
.then(function f (value){
    console.log('Value in first then', value);
    return value*2
}) // return promise pr2 {value: undefined, state: pending, onFulFilled: [g], onRejected: []}
.then(function g (value){
    console.log('Value in second then', value);
    return value*3
}) // return promise pr3 {value: undefined, state: pending, onFulFilled: [h], onRejected: []}
.then(function h(value){
    console.log('Value in third then', value);
    return value*4
}) // return promise pr4 {value: undefined, state: pending, onFulFilled: [], onRejected: []}


/*

// the above code and below code is identical

 const pr1 = createPromise(10000);
 const pr2 = pr1.then(function f(value) {
    console.log("Value in first then", value);
    return value*2;
});

const pr3 = pr2.then(function g(value) {
    console.log("Value in second then", value);
    return value*2;
});

const pr4 = pr3..then(function h(value) {
    console.log("Value in third then", value);
    return value*2;
});

*/
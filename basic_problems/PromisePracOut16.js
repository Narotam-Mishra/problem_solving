
// Find output of below code

const p1 = Promise.resolve("calling next");

const p2 = p1.then();

p2.then(
    (value) => {
        console.log("f2", p2);
        console.log("next promise's onFulfilled");
        console.log(value);
    },
    (reason) => {
        console.log(p2);
        console.log("next promise's onRejected");
        console.log(reason);
    }
)
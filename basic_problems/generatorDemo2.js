
// generator function example - 2

function* generatorDemo2(){
    console.log('Start');
    yield 10;

    console.log("middle");

    const x = 10 + (yield 30);

    console.log('Value of x:', x);
    yield x;
}
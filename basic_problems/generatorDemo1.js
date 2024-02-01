
// genertor demo example - 1

/*

task of yield :-

1). it will immediately bring control out of a generator function
2). whatever value we yield with is given to the 'value' property of returned iterator object.
3). if there are more yield left in generator function then 'done' property is false. 

*/

function* generatorDemo1(){
    console.log("line 1");
    yield "sanket";
    console.log("line 2");
    yield 2;
    console.log("line 3");
    yield 3;
    console.log("line 4");
    yield 4;
    console.log("line 5");
    yield 5;
    console.log("line 6");
    yield 6;
    console.log("line 7");
}

let x = generatorDemo1();

console.log(x.next());
console.log("Is paused");
console.log(x.next());
console.log("Is paused");
console.log(x.next());
console.log("Is paused");
console.log(x.next());
console.log(x.next());
console.log(x.next());
console.log(x.next());
console.log(x.next());
console.log(x.next());
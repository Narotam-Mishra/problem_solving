
// this example - 3

const obj = {
    x: 10,
    y: 20,

    displayProp:() => {
        console.log(`Value of x is: ${this.x} and y is: ${this.y}`);
    }
}

obj.displayProp();

// global's this 
console.log(this);
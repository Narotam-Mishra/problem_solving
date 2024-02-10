
// this example - 1

const obj = {
    x: 10,
    y: 20,

    displayProp: function(){
        console.log(`Value of x is: ${this.x} and y is: ${this.y}`);
    }
}

obj.displayProp();
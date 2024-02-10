
// this example - 2

const obj = {
    x: 10,
    y: 20,

    nestedProp: {
        z: 33,
        y: 25,

        displayFromInner: function(){
            console.log(`Value of x is: ${this.x} and y is: ${this.y}`);
        }
    },

    displayFromOuter: function(){
        console.log(`Value of x is: ${this.x} and y is: ${this.y}`);
    }
}

obj.displayFromOuter();
obj.nestedProp.displayFromInner();
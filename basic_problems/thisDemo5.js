
// this example - 5

const obj = {
    x: 10,
    y: 20,

    displayProp: function() {
        console.log(`Value of x is: ${this.x} and y is: ${this.y} from Outer`);
    
        const innerFn = () => {
            console.log(`Value of x is: ${this.x} and y is: ${this.y} from Inner`);
        }

        innerFn();
    }
}

obj.displayProp();

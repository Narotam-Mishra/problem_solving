
// this example - 6

const obj = {
    x: 10,
    y: 20,

    displayProp: function() {
        console.log(`Value of x is: ${this.x} and y is: ${this.y} from Outer`);
    
        const innerObj = {
            x: -1,
            y: -4,
            inner: () => {
                console.log(`Value of x is: ${this.x} and y is: ${this.y} from Inner`);
            }
        }
        innerObj.inner();
    }
}

obj.displayProp();

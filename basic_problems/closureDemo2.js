
// closure exaple - 2

function createCounter(){
    let count = 0;
    return{
        // returning object
        increment: function() { count += 1;},
        decrement: function() { count -= 1},
        getCount: function() { return count },
    }
}

let c = createCounter();
c.increment();
c.increment();
console.log(c.getCount());
c.decrement();
console.log(c.getCount());
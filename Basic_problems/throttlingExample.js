
// Throttling in JS

function throttle(func, delay){
    let lastCall = 0;

    return function(...args){
        const now = new Date().getTime();

        if(now - lastCall < delay){
            // not enough time has passed since the last call, do nothing
            return;
        }

        // enough time has passed, call the function the need to be throttled
        lastCall = now;
        func(...args);
    };
}

// example usage:

// function to be trottled
function handleInput(event){
    console.log("Input Received:", event.target.value);
}
// Throttle the input handling function to only run once every 1000 milliseconds
const throttledHandleInput = throttle(handleInput, 1000);

// Attach the throttle function to an input element
document.getElementById('myInput').addEventListener('input', throttledHandleInput);
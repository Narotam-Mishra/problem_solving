
// 8. Design a function which helps to do throttling

function throttle(fn, delay, context){
    let timerId, lastArgs;

    return function(...args){
        lastArgs = args;
        context = this ?? context;

        if(timerId) return;

        timerId = setTimeout(() => {
            fn.apply(context, lastArgs);
            clearTimeout(timerId);
        }, delay);
    };
}
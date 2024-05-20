
// 7. Design a function which helps to do debouncing

function debounce(fn, delay, context){
    let timerId;

    return function(...args){
        if(timerId) clearTimeout(timer);

        context = this ?? context;
        timerId = setTimeout(() => {
            fn.apply(context, args);
        }, delay);
    };
}
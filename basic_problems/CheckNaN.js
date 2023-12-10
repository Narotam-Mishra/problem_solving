//Problem1 - If NaN is never equal to itself, let's say that we want to write a function that returns NaN for something, but now how do we check if the function returned NaN ?

function fun() {
    console.log('Working with NaN');

    return NaN;
}

const response = fun();

if(isNaN(response)){
    console.log('Returned value is NaN');
}else{
    console.log('Returned value is not NaN');
}

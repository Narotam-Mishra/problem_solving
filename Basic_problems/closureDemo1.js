
// closure example - 1

function outer(){
    let i = 0;
    let j = [1,2,3];
    let k = "closure";

    function inner(){
        i += 1;
        console.log("value of j:",j);
        return i;
    }

    i += 2;
    return inner;
}

x = outer();

x();
x();

async function myFunc(){
    return "Hello"
}

// Approach - 1

let p = myFunc();
p.then(r => console.log(r));

// Approach - 2

async function printText(){
    const res = await myFunc();
    console.log(res);
}

printText()

let fizzBuzz =  function printFizzBuzz(n){
    let res = []
    for (let i=1; i<=n; i++){
        if(i%3===0 && i%5===0){
            res.push("FizzBuzz")
            // process.stdout.write('FizzBuzz'+ " ");
        }else if(i%3===0){
            res.push("Fizz");
            // process.stdout.write('Fizz'+ " ");
        }else if(i%5===0){
            res.push("Buzz")
            // process.stdout.write('Buzz'+ " ");
        }else{
            res.push(i.toString());
            // process.stdout.write(i+ " ");
        }
    }
    return res;
}

let res = fizzBuzz(50);
console.log(...res);
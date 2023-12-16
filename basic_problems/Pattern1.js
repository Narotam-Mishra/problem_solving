
function pattern1Print(n){
    for (let i=0; i<n; i++){
        for (let j=0; j<i+1; j++){
            process.stdout.write("*");
        }
        console.log();
    }
}

let n = 15;
pattern1Print(n);
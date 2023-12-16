

function pattern2Print(n){
    for(let i=1; i<=n; i++){
        for(let j=1; j<=n; j++){
            process.stdout.write("*");
        }
        console.log();
    }
}

let n = 9;
pattern2Print(n)
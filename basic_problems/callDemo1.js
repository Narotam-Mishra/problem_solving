
// call() demo example-1


const player1 = {
    fNamne: "Virat",
    lName: "Kohli",
    noToBat: 3
}

const player2 = {
    fNamne: "Yuvraj",
    lName: "Singh",
    noToBat: 5
}

const showDetails = function (x,y) {
    console.log(this);  // {}
    console.log('Sum:',x+y);
    console.log(`${this.fNamne + ' ' +this.lName} comes to bat at ${this.noToBat}`);
}

showDetails.call(player1,10,20);
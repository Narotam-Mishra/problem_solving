
// bind() demo example-1

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

const showDetails = function () {
    console.log(this);  // {}
    console.log(`${this.fNamne + ' ' +this.lName} comes to bat at ${this.noToBat}`);
}

// showDetails();

const displayDetails1 = showDetails.bind(player1);
const displayDetails2 = showDetails.bind(player2);

displayDetails1();
displayDetails2();
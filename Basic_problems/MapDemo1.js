
// Map demo example - 1

const m1 = new Map();

m1.set('name', 'Naru');
m1.set('age', 25);

m1.set('hobby', 'teaching')

// console.log(m1.get("name"));
// console.log(m1.get("age"));

for(entry of m1){
    console.log(entry);
}

m1.forEach((key, val) => {
    console.log(key,":", val);
})